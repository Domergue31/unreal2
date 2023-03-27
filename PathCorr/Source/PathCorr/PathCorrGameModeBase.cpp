// Copyright Epic Games, Inc. All Rights Reserved.


#include "PathCorrGameModeBase.h"

void APathCorrGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	pathManager = NewObject<UPathhManager>(this);
	pawnSwitcher = GetWorld()->SpawnActor<APawnSwitcher>();
}
