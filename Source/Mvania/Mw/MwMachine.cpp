#include "MwMachine.h"
#include "MwCafeConfig.h"
#include "MwCat.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AMwMachine::AMwMachine()
{
	PrimaryActorTick.bCanEverTick = false;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	if (Cube.Succeeded()) Body->SetStaticMesh(Cube.Object);
	Body->SetCollisionProfileName(TEXT("BlockAll"));
	Label = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Label"));
	Label->SetupAttachment(Body);
	Label->SetRelativeLocation(FVector(-60.f, 0.f, 90.f));
	Label->SetRelativeRotation(FRotator(40.f, 180.f, 0.f)); // toward the fixed camera (it looks along +X, 50 degrees down)
	Label->SetHorizontalAlignment(EHTA_Center);
	Label->SetWorldSize(28.f);
	Label->SetTextRenderColor(FColor(0x2a, 0x1a, 0x2e));
	Tags.Add(TEXT("Usable"));
}

void AMwMachine::Setup(FName InKind, const FMwMachineRow& InRow)
{
	Kind = InKind;
	Row = InRow;
	Stock = Row.Start;
	Body->SetRelativeScale3D(FVector(0.8f, 0.8f, 1.f) * Row.Scale);
	Refresh();
}

void AMwMachine::Refresh()
{
	FString Text = Row.Label.ToString();
	if (Jammed()) Text += TEXT("\nJAMMED");
	else if (Row.Cap > 0) Text += FString::Printf(TEXT("\n%d / %d"), Row.Makes.IsNone() ? Held.Num() : Stock, Row.Cap);
	Label->SetText(FText::FromString(Text));
}

FString AMwMachine::Use(AMwCat* Cat, const FMwCafeConfig& Cfg)
{
	// shortcut: every use is instant; the prototype's hold rings (churn 1.2 s, scoop 0.9 s, fix 2 s) come with the first feel pass
	FString Msg;
	FName& Carry = Cat->Carry;
	const bool Converts = !Row.From.IsNone();
	if (Jammed()) { Wear = 0.f; Msg = FString::Printf(TEXT("Fixed the %s"), *Row.Label.ToString()); }
	else if (Converts && Carry == Row.From && Stock < Row.Cap)
	{
		Carry = NAME_None;
		Stock += 1;
		Wear += Cfg.WearPerCycle;
		Msg = FString::Printf(TEXT("%s -> %s"), *Row.From.ToString(), *Row.Makes.ToString());
		if (Jammed()) Msg += TEXT(" ... and it jammed!");
	}
	else if (!Row.Makes.IsNone() && Carry.IsNone() && Stock > 0) { Stock -= 1; Carry = Row.Makes; Msg = FString::Printf(TEXT("Took a %s"), *Carry.ToString()); }
	else if (!Row.Makes.IsNone() && Carry.IsNone()) Msg = Converts ? FString::Printf(TEXT("Needs %s"), *Row.From.ToString()) : TEXT("Empty");
	else if (Kind == TEXT("counter") && Carry == TEXT("base")) { Carry = TEXT("cone:plain"); Msg = TEXT("Scooped a plain cone"); }
	else if (Kind == TEXT("counter") && Carry.ToString().StartsWith(TEXT("cone:")))
	{
		// shortcut: no customers yet, so the counter buys any cone at list price
		const FName Flavour(*Carry.ToString().RightChop(5));
		const int32 Price = Cfg.Prices.FindRef(Flavour);
		Cat->Coin += Price;
		Carry = NAME_None;
		Msg = FString::Printf(TEXT("Sold a %s cone, +%d coin"), *Flavour.ToString(), Price);
	}
	else if (Kind == TEXT("bin") && !Carry.IsNone()) { Msg = FString::Printf(TEXT("Tossed the %s"), *Carry.ToString()); Carry = NAME_None; }
	else if (Kind == TEXT("coldbox") && !Carry.IsNone() && Held.Num() < Row.Cap) { Held.Add(Carry); Msg = FString::Printf(TEXT("Kept the %s cold"), *Carry.ToString()); Carry = NAME_None; }
	else if (Kind == TEXT("coldbox") && Carry.IsNone() && Held.Num()) { Carry = Held.Pop(); Msg = FString::Printf(TEXT("Took the %s back"), *Carry.ToString()); }
	else Msg = Carry.IsNone() ? TEXT("Nothing to do here") : FString::Printf(TEXT("Can't use the %s here"), *Carry.ToString());
	Refresh();
	return Msg;
}
