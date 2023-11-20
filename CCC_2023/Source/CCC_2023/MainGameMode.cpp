// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "CameraManager_C.h"

void AMainGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	if (cameraManagerRef)
		currentCameraManagerInstance = NewObject<UCameraManager_C>(this, cameraManagerRef);
}
