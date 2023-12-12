// MIT Licence

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CUSTOMLOGGING_LF_API FCustomLog_Lf final : public FOutputDevice
{
public:
	virtual void Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const class FName& Category) override;
	static bool WriteLogFile(const FString& DataToSave, const FString& FileName);
	static bool ClearData(const FString& FileName);

	inline static FString LogFileName = FString("CustomLogFile.txt");
};
