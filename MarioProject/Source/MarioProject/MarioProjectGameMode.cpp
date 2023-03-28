// Copyright Epic Games, Inc. All Rights Reserved.

#include "MarioProjectGameMode.h"
#include "MarioProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMarioProjectGameMode::AMarioProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
