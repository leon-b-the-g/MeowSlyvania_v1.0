#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MwCafeConfig.h"
#include "MwGameMode.generated.h"

class UDataTable;
class AMwMachine;

/** Meowsylvania's game mode: the player is a MwCat; the yard gets its floor and the starting machines from Data/. */
UCLASS()
class AMwGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMwGameMode();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Mw") FMwCafeConfig Cafe;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") TObjectPtr<UDataTable> Machines;
	UPROPERTY(EditAnywhere, Category = "Mw") float TileSize = 100.f;

	/** Spawn a machine of Kind on yard tile (Tx east, Tz south); null if the kind is unknown. */
	AMwMachine* PlaceMachine(FName Kind, int32 Tx, int32 Tz);
};
