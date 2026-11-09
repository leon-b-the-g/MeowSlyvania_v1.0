// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Mvania : ModuleRules
{
	public Mvania(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "Json", "JsonUtilities" });

		PublicIncludePaths.AddRange(new string[] {
			"Mvania",
			"Mvania/Mw",
			"Mvania/Variant_Strategy",
			"Mvania/Variant_Strategy/UI",
			"Mvania/Variant_TwinStick",
			"Mvania/Variant_TwinStick/AI",
			"Mvania/Variant_TwinStick/Gameplay",
			"Mvania/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
