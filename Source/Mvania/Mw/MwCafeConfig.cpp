#include "MwCafeConfig.h"
#include "Mvania.h"
#include "Engine/DataTable.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

static FString ReadData(const TCHAR* File)
{
	FString Json;
	const FString Path = FPaths::ProjectDir() / TEXT("Data") / File;
	if (!FFileHelper::LoadFileToString(Json, *Path)) UE_LOG(LogMvania, Error, TEXT("Missing %s"), *Path);
	return Json;
}

FMwCafeConfig Mw::LoadCafeConfig()
{
	FMwCafeConfig Cfg;
	const FString Json = ReadData(TEXT("Cafe.json"));
	if (!Json.IsEmpty() && !FJsonObjectConverter::JsonObjectStringToUStruct(Json, &Cfg)) UE_LOG(LogMvania, Error, TEXT("Data/Cafe.json does not parse"));
	return Cfg;
}

UDataTable* Mw::LoadMachineTable(UObject* Outer)
{
	UDataTable* Table = NewObject<UDataTable>(Outer);
	Table->RowStruct = FMwMachineRow::StaticStruct();
	const FString Json = ReadData(TEXT("DT_Machines.json"));
	for (const FString& Problem : Table->CreateTableFromJSONString(Json)) UE_LOG(LogMvania, Error, TEXT("DT_Machines.json: %s"), *Problem);
	return Table;
}
