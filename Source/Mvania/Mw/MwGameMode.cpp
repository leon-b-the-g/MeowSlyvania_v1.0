#include "MwGameMode.h"
#include "MwCat.h"
#include "MwTileFloor.h"
#include "EngineUtils.h"

AMwGameMode::AMwGameMode()
{
	DefaultPawnClass = AMwCat::StaticClass();
}

void AMwGameMode::BeginPlay()
{
	Super::BeginPlay();
	TActorIterator<AMwTileFloor> Existing(GetWorld());
	if (!Existing) GetWorld()->SpawnActor<AMwTileFloor>(FVector::ZeroVector, FRotator::ZeroRotator);
}
