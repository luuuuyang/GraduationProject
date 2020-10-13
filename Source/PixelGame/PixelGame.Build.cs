// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PixelGame : ModuleRules
{
	public PixelGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D", "UMG", "Slate", "SlateCore", "GameplayTags", "AIModule", "GameplayTasks" });
	}
}
