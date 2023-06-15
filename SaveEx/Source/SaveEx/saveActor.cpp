// Fill out your copyright notice in the Description page of Project Settings.


#include "saveActor.h"
#include "SaveGameInstance.h"

void AsaveActor::BeginPlay()
{
	Super::BeginPlay();
	InitDatas();
	FTimerHandle _saveTimer;
	GetWorldTimerManager().SetTimer(_saveTimer, this, &AsaveActor::AutoSavePlayerExample, 5, true);
}

void AsaveActor::InitDatas()
{
	USaveGameInstance* _instance = GetWorld()->GetGameInstance<USaveGameInstance>();
	if (!_instance)
		return;
	_instance->GetSaveManager()->Load(this);
	_instance->GetSaveManager()->Save(this);
}

void AsaveActor::AutoSavePlayerExample()
{
	USaveGameInstance* _instance = GetWorld()->GetGameInstance<USaveGameInstance>();
	if (!_instance)
		return;
	_instance->GetSaveManager()->Save(this);
}
