// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CLocalMultiplayerEditorTarget : TargetRules
{
	public CLocalMultiplayerEditorTarget( TargetInfo Target) : base(Target) 
	{
		Name = "CLocalMultiplayerEditor";
		
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("CLocalMultiplayer");
	}
}
