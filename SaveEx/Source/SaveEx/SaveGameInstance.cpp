// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameInstance.h"

void USaveGameInstance::Init()
{
	Super::Init();
	saveManager = NewObject<USaveManager>(this);
	if (!saveManager)
		return;
	saveManager->Init();
}
