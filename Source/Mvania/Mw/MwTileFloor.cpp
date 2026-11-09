#include "MwTileFloor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

AMwTileFloor::AMwTileFloor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Plane(TEXT("/Engine/BasicShapes/Plane.Plane")); // 100 x 100 uu
	// shortcut: the template's prototype-grid materials stand in for the ground atlas until the tile art lands
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatA(TEXT("/Game/LevelPrototyping/Materials/MI_PrototypeGrid_Gray.MI_PrototypeGrid_Gray"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatB(TEXT("/Game/LevelPrototyping/Materials/MI_PrototypeGrid_Gray_02.MI_PrototypeGrid_Gray_02"));
	Even = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Even"));
	Odd = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Odd"));
	for (UInstancedStaticMeshComponent* C : { Even.Get(), Odd.Get() })
	{
		C->SetupAttachment(RootComponent);
		if (Plane.Succeeded()) C->SetStaticMesh(Plane.Object);
		C->SetCollisionProfileName(TEXT("BlockAll"));
	}
	if (MatA.Succeeded()) Even->SetMaterial(0, MatA.Object);
	if (MatB.Succeeded()) Odd->SetMaterial(0, MatB.Object);
}

void AMwTileFloor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	Even->ClearInstances();
	Odd->ClearInstances();
	const float S = TileSize / 100.f;
	for (int32 X = 0; X < Width; X++)
		for (int32 Y = 0; Y < Depth; Y++)
		{
			const FVector Pos((X - Width / 2 + 0.5f) * TileSize, (Y - Depth / 2 + 0.5f) * TileSize, 0.f);
			((X + Y) % 2 ? Odd : Even)->AddInstance(FTransform(FRotator::ZeroRotator, Pos, FVector(S, S, 1.f)));
		}
}
