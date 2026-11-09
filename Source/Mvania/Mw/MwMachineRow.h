#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MwMachineRow.generated.h"

/** One cafe machine kind (DT_Machines, imported from Data/DT_Machines.json; prototype data/machines.json "kinds"). */
USTRUCT(BlueprintType)
struct FMwMachineRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly) FText Label;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) int32 Cost = 0;
	/** Item this machine produces per cycle; None = hand-operated only. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FName Makes;
	/** Item a cycle consumes (taken from any machine holding it); None = nothing. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FName From;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) float CycleSec = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) int32 Cap = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly) int32 Start = 0;
	/** Drawn size, 1 = one prop cell. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly) float Scale = 1.f;
	/** Conquered regions needed before it can be built. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly) int32 Land = 0;
};
