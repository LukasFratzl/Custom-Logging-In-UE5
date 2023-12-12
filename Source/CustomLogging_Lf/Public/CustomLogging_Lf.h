// MIT Licence

#pragma once

#include "CoreMinimal.h"
#include "CustomLog_Lf.h"
#include "Modules/ModuleManager.h"

class FCustomLogging_LfModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    FCustomLog_Lf CustomLogOutputDevice;
};
