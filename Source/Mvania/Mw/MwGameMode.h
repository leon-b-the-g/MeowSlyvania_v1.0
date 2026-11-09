#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MwGameMode.generated.h"

/** Meowsylvania's game mode: the player is a MwCat; a level without a MwTileFloor gets one at the origin. */
UCLASS()
class AMwGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMwGameMode();
	virtual void BeginPlay() override;
};
