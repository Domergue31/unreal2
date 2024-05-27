// Copyright Epic Games, Inc. All Rights Reserved.

#include "VoiceChatProjectGameMode.h"
#include "VoiceChatProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVoiceChatProjectGameMode::AVoiceChatProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
