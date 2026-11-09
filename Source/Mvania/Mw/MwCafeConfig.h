#pragma once

#include "CoreMinimal.h"
#include "MwMachineRow.h"
#include "MwCafeConfig.generated.h"

class UDataTable;

USTRUCT()
struct FMwCafeStart
{
	GENERATED_BODY()
	UPROPERTY() FName Kind;
	UPROPERTY() int32 Tx = 0;
	UPROPERTY() int32 Tz = 0;
};

/** Data/Cafe.json: the day clock, wear and jams, prices, the starting machines. */
USTRUCT()
struct FMwCafeConfig
{
	GENERATED_BODY()
	UPROPERTY() float RealSecondsPerDay = 540.f;
	UPROPERTY() float Dawn = 6.f;
	UPROPERTY() float ShopOpen = 10.f;
	UPROPERTY() float Dusk = 18.f;
	UPROPERTY() float FixSec = 2.f;
	UPROPERTY() float WearPerCycle = 0.08f;
	UPROPERTY() TMap<FName, int32> Prices;
	UPROPERTY() TArray<FMwCafeStart> Starting;
};

// shortcut: tunables are read from <Project>/Data/*.json at runtime, not from cooked assets; add Data/ to
// "Additional Non-Asset Directories To Copy" (Project Settings > Packaging) before the first packaged build.
namespace Mw
{
	/** Data/Cafe.json, or defaults with an error logged. */
	FMwCafeConfig LoadCafeConfig();
	/** Data/DT_Machines.json as a transient DataTable of FMwMachineRow. */
	UDataTable* LoadMachineTable(UObject* Outer);
}
