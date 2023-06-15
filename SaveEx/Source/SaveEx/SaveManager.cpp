// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "Kismet/GameplayStatics.h"

void USaveManager::Init()
{
	progress = NewObject<UGameProgress>(this);
}

void USaveManager::Save(AsaveActor* _actor)
{
	progress->SetSaveLife(_actor->GetLife());
	bool _saved = UGameplayStatics::SaveGameToSlot(progress, "SaveProgress", 0);
	if (_saved)
		UE_LOG(LogTemp, Warning, TEXT("Game Saved !"));
}

void USaveManager::Load(AsaveActor* _actor)
{
	USaveGame* _save = UGameplayStatics::LoadGameFromSlot("SaveProgress", 0);
	if (!_save)
		return;
	UGameProgress* _progress = Cast<UGameProgress>(_save);
	progress = _progress;
	_actor->SetLife(progress->GetSaveLife());
}
