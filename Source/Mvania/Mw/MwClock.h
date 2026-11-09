#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MwClock.generated.h"

/** The game day: RealSecondsPerDay real seconds from dawn to dawn (Data/Cafe.json). Hour() is 0..24. */
UCLASS()
class UMwClock : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Mw") int32 Day = 1;
	/** Fraction of the day, 0 = midnight. */
	UPROPERTY(BlueprintReadOnly, Category = "Mw") float Time = 0.25f;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") float RealSecondsPerDay = 540.f;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") float ShopOpen = 10.f;
	UPROPERTY(BlueprintReadOnly, Category = "Mw") float Dusk = 18.f;

	UFUNCTION(BlueprintPure, Category = "Mw") float Hour() const { return Time * 24.f; }
	UFUNCTION(BlueprintPure, Category = "Mw") bool IsOpen() const { return Hour() >= ShopOpen && Hour() < Dusk; }
	UFUNCTION(BlueprintPure, Category = "Mw") FString Clock() const;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override { return WorldType == EWorldType::Game || WorldType == EWorldType::PIE; }
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UMwClock, STATGROUP_Tickables); }
};
