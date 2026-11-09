#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MwMachineRow.h"
#include "MwMachine.generated.h"

class AMwCat;
class UStaticMeshComponent;
class UTextRenderComponent;
struct FMwCafeConfig;

/** A cafe machine on a yard tile: holds a stock of what it makes, wears with every cycle, jams at 1.0. */
UCLASS()
class AMwMachine : public AActor
{
	GENERATED_BODY()

public:
	AMwMachine();

	UPROPERTY(BlueprintReadOnly, Category = "Mw") FName Kind;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") FMwMachineRow Row;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") int32 Stock = 0;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") float Wear = 0.f;
	/** What a store (cold box) keeps, oldest first. */
	UPROPERTY(BlueprintReadOnly, Category = "Mw") TArray<FName> Held;

	void Setup(FName InKind, const FMwMachineRow& InRow);
	bool Jammed() const { return Wear >= 1.f; }
	/** The cat uses this machine once; returns the toast to show. */
	FString Use(AMwCat* Cat, const FMwCafeConfig& Cfg);

protected:
	// shortcut: a cube with a floating label stands in for the prop sprite
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UStaticMeshComponent> Body;
	UPROPERTY(VisibleAnywhere, Category = "Mw") TObjectPtr<UTextRenderComponent> Label;
	void Refresh();
};
