// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardGameMode.h"

void AGuardGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	if (pathManagerRef)
		pathManager = NewObject<UPathManager>(this, pathManagerRef);
}

