#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MwTileFloor.generated.h"

class UInstancedStaticMeshComponent;

/** The cafe yard: a Width x Depth checkerboard of flat tiles centred on the actor (prototype GRID 32). */
UCLASS()
class AMwTileFloor : public AActor
{
	GENERATED_BODY()

public:
	AMwTileFloor();

	UPROPERTY(EditAnywhere, Category = "Mw") int32 Width = 32;
	UPROPERTY(EditAnywhere, Category = "Mw") int32 Depth = 32;
	UPROPERTY(EditAnywhere, Category = "Mw") float TileSize = 100.f;

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// two meshes, one per checker colour (an instanced mesh has one material)
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UInstancedStaticMeshComponent> Even;
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UInstancedStaticMeshComponent> Odd;
};
