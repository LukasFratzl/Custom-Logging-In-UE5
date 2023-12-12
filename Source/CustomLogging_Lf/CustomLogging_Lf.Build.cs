﻿// MIT Licence

using UnrealBuildTool;

public class CustomLogging_Lf : ModuleRules
{
    public CustomLogging_Lf(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
               "Core",
            }
        );
    }
}