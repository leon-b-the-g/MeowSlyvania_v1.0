#include "MwCat.h"
#include "Mvania.h"
#include "Camera/CameraComponent.h"
#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "Engine/OverlapResult.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AMwCat::AMwCat()
{
	PrimaryActorTick.bCanEverTick = true;

	// the camera never turns: one fixed top-down angle for cafe, map and battle
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritYaw = SpringArm->bInheritPitch = SpringArm->bInheritRoll = false;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cylinder(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	GetCapsuleComponent()->InitCapsuleSize(40.f, 60.f); // a cat is about a tile wide
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(RootComponent);
	Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Body->SetRelativeScale3D(FVector(0.8f, 0.8f, 1.2f));
	if (Cylinder.Succeeded()) Body->SetStaticMesh(Cylinder.Object);
	Nose = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Nose"));
	Nose->SetupAttachment(RootComponent);
	Nose->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Nose->SetRelativeLocation(FVector(45.f, 0.f, 30.f));
	Nose->SetRelativeScale3D(FVector(0.2f));
	if (Cube.Succeeded()) Nose->SetStaticMesh(Cube.Object);

	bUseControllerRotationYaw = false;
	UCharacterMovementComponent* Move = GetCharacterMovement();
	Move->bOrientRotationToMovement = true; // the cat faces where it walks
	Move->RotationRate = FRotator(0.f, 720.f, 0.f);
	Move->bConstrainToPlane = true;
	Move->bSnapToPlaneAtStart = true;
	Move->MaxAcceleration = 4000.f;
	Move->BrakingDecelerationWalking = 4000.f;
}

void AMwCat::BuildInput()
{
	if (Mapping) return;
	Mapping = NewObject<UInputMappingContext>(this);
	MoveAction = NewObject<UInputAction>(this);
	MoveAction->ValueType = EInputActionValueType::Axis2D; // X = right (+Y world), Y = forward (+X world)
	SprintAction = NewObject<UInputAction>(this);
	UseAction = NewObject<UInputAction>(this);

	Mapping->MapKey(MoveAction, EKeys::D);
	Mapping->MapKey(MoveAction, EKeys::A).Modifiers.Add(NewObject<UInputModifierNegate>(this));
	Mapping->MapKey(MoveAction, EKeys::W).Modifiers.Add(NewObject<UInputModifierSwizzleAxis>(this)); // YXZ: key value into Y
	FEnhancedActionKeyMapping& S = Mapping->MapKey(MoveAction, EKeys::S);
	S.Modifiers.Add(NewObject<UInputModifierSwizzleAxis>(this));
	S.Modifiers.Add(NewObject<UInputModifierNegate>(this));
	Mapping->MapKey(MoveAction, EKeys::Gamepad_Left2D);
	Mapping->MapKey(SprintAction, EKeys::LeftShift);
	Mapping->MapKey(SprintAction, EKeys::Gamepad_FaceButton_Right);
	Mapping->MapKey(UseAction, EKeys::E);
	Mapping->MapKey(UseAction, EKeys::SpaceBar);
	Mapping->MapKey(UseAction, EKeys::Gamepad_FaceButton_Bottom);
}

void AMwCat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	BuildInput();
	if (const APlayerController* PC = Cast<APlayerController>(Controller))
		if (UEnhancedInputLocalPlayerSubsystem* Sub = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
			if (!Sub->HasMappingContext(Mapping)) Sub->AddMappingContext(Mapping, 0);
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EIC) { UE_LOG(LogMvania, Error, TEXT("MwCat needs the Enhanced Input component (Project Settings > Input)")); return; }
	EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMwCat::Move);
	EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AMwCat::SprintStart);
	EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMwCat::SprintStop);
	EIC->BindAction(UseAction, ETriggerEvent::Started, this, &AMwCat::Use);
}

void AMwCat::Move(const FInputActionValue& Value)
{
	const FVector2D In = Value.Get<FVector2D>();
	AddMovementInput(FVector::ForwardVector, In.Y);
	AddMovementInput(FVector::RightVector, In.X);
}

void AMwCat::SprintStart(const FInputActionValue&) { bSprinting = Stamina >= MinToSprint; }
void AMwCat::SprintStop(const FInputActionValue&) { bSprinting = false; }

void AMwCat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpringArm->SetRelativeRotation(FRotator(CameraPitch, 0.f, 0.f));
	SpringArm->TargetArmLength = CameraDistance;
	Camera->SetFieldOfView(CameraFov);

	const bool Moving = GetVelocity().SizeSquared2D() > 1.f;
	if (bSprinting && Moving) Stamina -= DeltaTime / DrainSec;
	else Stamina += DeltaTime / RegenSec;
	Stamina = FMath::Clamp(Stamina, 0.f, 1.f);
	if (Stamina <= 0.f) bSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = (bSprinting ? SprintSpeed : Speed) * TileSize;
}

void AMwCat::Use(const FInputActionValue&)
{
	// anything tagged "Usable" within Reach, nearest first, in front of the cat
	const FVector Here = GetActorLocation();
	TArray<FOverlapResult> Hits;
	GetWorld()->OverlapMultiByObjectType(Hits, Here, FQuat::Identity, FCollisionObjectQueryParams(FCollisionObjectQueryParams::InitType::AllObjects), FCollisionShape::MakeSphere(Reach * TileSize));
	AActor* Best = nullptr;
	float BestScore = TNumericLimits<float>::Max();
	for (const FOverlapResult& H : Hits)
	{
		AActor* A = H.GetActor();
		if (!A || A == this || !A->ActorHasTag(TEXT("Usable"))) continue;
		const FVector To = (A->GetActorLocation() - Here).GetSafeNormal2D();
		const float Score = FVector::Dist2D(A->GetActorLocation(), Here) - 0.5f * TileSize * FVector::DotProduct(To, GetActorForwardVector());
		if (Score < BestScore) { BestScore = Score; Best = A; }
	}
	const FString Msg = Best ? FString::Printf(TEXT("Use %s"), *Best->GetName()) : TEXT("Nothing to use here");
	UE_LOG(LogMvania, Log, TEXT("%s"), *Msg);
	if (GEngine) GEngine->AddOnScreenDebugMessage(1, 1.5f, FColor(0xc0, 0x24, 0x3a), Msg);
}
