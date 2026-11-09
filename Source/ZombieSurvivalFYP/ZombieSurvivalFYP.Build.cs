// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ZombieSurvivalFYP : ModuleRules
{
	public ZombieSurvivalFYP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ZombieSurvivalFYP",
			"ZombieSurvivalFYP/Variant_Horror",
			"ZombieSurvivalFYP/Variant_Horror/UI",
			"ZombieSurvivalFYP/Variant_Shooter",
			"ZombieSurvivalFYP/Variant_Shooter/AI",
			"ZombieSurvivalFYP/Variant_Shooter/UI",
			"ZombieSurvivalFYP/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
