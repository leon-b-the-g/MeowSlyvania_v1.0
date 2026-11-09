#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MwCat.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/** The player's cat: top-down walk (WASD / left stick), sprint on a stamina bar, use the thing in front of you. */
UCLASS()
class AMwCat : public ACharacter
{
	GENERATED_BODY()

public:
	AMwCat();

	/** Walking speed, tiles/s (prototype player.json "speed"; a tile is TileSize uu). */
	UPROPERTY(EditAnywhere, Category = "Mw|Move") float Speed = 6.f;
	UPROPERTY(EditAnywhere, Category = "Mw|Move") float SprintSpeed = 10.5f;
	/** Full stamina drains in DrainSec of sprinting and refills in RegenSec of not. Sprint needs MinToSprint. */
	UPROPERTY(EditAnywhere, Category = "Mw|Move") float DrainSec = 3.f;
	UPROPERTY(EditAnywhere, Category = "Mw|Move") float RegenSec = 4.f;
	UPROPERTY(EditAnywhere, Category = "Mw|Move") float MinToSprint = 0.15f;
	UPROPERTY(EditAnywhere, Category = "Mw|Move") float TileSize = 100.f;
	/** How far in front of the cat "use" reaches, in tiles (prototype target.ts reach 2.4). */
	UPROPERTY(EditAnywhere, Category = "Mw|Use") float Reach = 2.4f;

	UPROPERTY(EditAnywhere, Category = "Mw|Camera") float CameraPitch = -50.f;
	UPROPERTY(EditAnywhere, Category = "Mw|Camera") float CameraDistance = 6000.f;
	UPROPERTY(EditAnywhere, Category = "Mw|Camera") float CameraFov = 20.f;

	UPROPERTY(BlueprintReadOnly, Category = "Mw") float Stamina = 1.f;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") bool bSprinting = false;

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UCameraComponent> Camera;
	// shortcut: a cylinder with a nose cube stands in for the cat sprite until the billboard/flipbook pass
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UStaticMeshComponent> Body;
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UStaticMeshComponent> Nose;

	// shortcut: input actions and the mapping context are built in code at possess time (keys below),
	// not authored as IA_/IMC_ assets; upgrade to assets when the first editor asset pass happens.
	UPROPERTY() TObjectPtr<UInputMappingContext> Mapping;
	UPROPERTY() TObjectPtr<UInputAction> MoveAction;
	UPROPERTY() TObjectPtr<UInputAction> SprintAction;
	UPROPERTY() TObjectPtr<UInputAction> UseAction;

	void BuildInput();
	void Move(const FInputActionValue& Value);
	void SprintStart(const FInputActionValue& Value);
	void SprintStop(const FInputActionValue& Value);
	void Use(const FInputActionValue& Value);
};
