#include "MwGameMode.h"
#include "Mvania.h"
#include "MwCat.h"
#include "MwMachine.h"
#include "MwTileFloor.h"
#include "Engine/DataTable.h"
#include "EngineUtils.h"

AMwGameMode::AMwGameMode()
{
	DefaultPawnClass = AMwCat::StaticClass();
}

void AMwGameMode::BeginPlay()
{
	Super::BeginPlay();
	Cafe = Mw::LoadCafeConfig();
	Machines = Mw::LoadMachineTable(this);
	TActorIterator<AMwTileFloor> Existing(GetWorld());
	if (!Existing) GetWorld()->SpawnActor<AMwTileFloor>(FVector::ZeroVector, FRotator::ZeroRotator);
	for (const FMwCafeStart& S : Cafe.Starting) PlaceMachine(S.Kind, S.Tx, S.Tz);
}

AMwMachine* AMwGameMode::PlaceMachine(FName Kind, int32 Tx, int32 Tz)
{
	const FMwMachineRow* Row = Machines ? Machines->FindRow<FMwMachineRow>(Kind, TEXT("PlaceMachine")) : nullptr;
	if (!Row) { UE_LOG(LogMvania, Error, TEXT("No machine kind '%s' in DT_Machines.json"), *Kind.ToString()); return nullptr; }
	// yard tiles: tx runs east (+Y on screen right), tz runs south (-X, down the screen); the cube sits on the floor
	const FVector Pos(-Tz * TileSize, Tx * TileSize, 50.f * Row->Scale);
	AMwMachine* M = GetWorld()->SpawnActor<AMwMachine>(Pos, FRotator::ZeroRotator);
	M->Setup(Kind, *Row);
	return M;
}
