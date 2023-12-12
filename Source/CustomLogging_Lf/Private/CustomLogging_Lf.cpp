// MIT Licence

#include "CustomLogging_Lf.h"

#define LOCTEXT_NAMESPACE "FCustomLogging_LfModule"

void FCustomLogging_LfModule::StartupModule()
{
	// Create an instance of your custom log output device
	CustomLogOutputDevice = FCustomLog_Lf();

	CustomLogOutputDevice.ClearData(FCustomLog_Lf::LogFileName);

	// Register the custom log output device with Unreal Engine's logging system
	GLog->AddOutputDevice(&CustomLogOutputDevice);
}

void FCustomLogging_LfModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FCustomLogging_LfModule, CustomLogging_Lf)