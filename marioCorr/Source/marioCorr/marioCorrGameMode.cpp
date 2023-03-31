// Copyright Epic Games, Inc. All Rights Reserved.

#include "marioCorrGameMode.h"
#include "marioCorrCharacter.h"
#include "UObject/ConstructorHelpers.h"

AmarioCorrGameMode::AmarioCorrGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
