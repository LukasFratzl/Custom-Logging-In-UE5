// MIT Licence


#include "CustomLog_Lf.h"

#include "HAL/PlatformFileManager.h"


void FCustomLog_Lf::Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const FName& Category)
{
	// Create a log message with category and verbosity
	const FString& LogMessage = FString::Printf(TEXT("[%s] %s"), *Category.ToString(), V);

	WriteLogFile(LogMessage, FCustomLog_Lf::LogFileName);
}

bool FCustomLog_Lf::WriteLogFile(const FString& DataToSave, const FString& FileName)
{
	// Get the path to the internal storage directory
	const FString& SaveDirectory = FPaths::ProjectPersistentDownloadDir();

	// Combine with the desired file name
	const FString& SavePath = FPaths::Combine(SaveDirectory, FileName);

	// Append the data to the file
	if (IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile(); PlatformFile.CreateDirectoryTree(*SaveDirectory))
	{
		// Open the file in append mode
		if (IFileHandle* FileHandle = PlatformFile.OpenWrite(*SavePath, true, true))
		{
			const FString& Data = FString::Printf(TEXT("%s\n"), *DataToSave);
			// Write the log message as UTF-8 text to the file
			FTCHARToUTF8 UTF8String(GetData(Data), Data.Len());
			FileHandle->Write((const uint8*)UTF8String.Get(), FCString::Strlen(GetData(Data)));

			// Close the file handle
			delete FileHandle;
            
			return true;
		}
	}
    
	return false;
}

bool FCustomLog_Lf::ClearData(const FString& FileName)
{
	// Get the path to the internal storage directory
	const FString& SaveDirectory = FPaths::ProjectPersistentDownloadDir();

	// Combine with the desired file name
	const FString& SavePath = FPaths::Combine(SaveDirectory, FileName);

	// Write the data to the file
	if (IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile(); PlatformFile.CreateDirectoryTree(*SaveDirectory))
	{
		FFileHelper::SaveStringToFile(FString(""), *SavePath);
		return true;
	}
	return false;
}
