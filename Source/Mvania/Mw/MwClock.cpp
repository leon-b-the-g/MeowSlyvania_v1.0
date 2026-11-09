#include "MwClock.h"
#include "MwCafeConfig.h"

void UMwClock::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	const FMwCafeConfig Cfg = Mw::LoadCafeConfig();
	RealSecondsPerDay = Cfg.RealSecondsPerDay;
	ShopOpen = Cfg.ShopOpen;
	Dusk = Cfg.Dusk;
	Time = Cfg.Dawn / 24.f;
}

void UMwClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime / RealSecondsPerDay;
	if (Time >= 1.f) { Time -= 1.f; Day += 1; }
}

FString UMwClock::Clock() const
{
	const int32 Minutes = FMath::FloorToInt(Hour() * 60.f);
	return FString::Printf(TEXT("Day %d  %02d:%02d"), Day, Minutes / 60, Minutes % 60);
}
