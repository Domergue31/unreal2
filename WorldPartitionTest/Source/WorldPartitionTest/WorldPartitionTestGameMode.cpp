// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldPartitionTestGameMode.h"
#include "WorldPartitionTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWorldPartitionTestGameMode::AWorldPartitionTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
