// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "MarioGameMode.h"

void APowerUp::Save(AMarioCharacter* _mario)
{
	AMarioGameMode* _gm = Cast<AMarioGameMode>(GetWorld()->GetAuthGameMode());
	if (!_gm)
		return;
	_gm->GetScore()->AddScore(1000);
	_mario->SaveData()->SavedCharacter(_mario);
}

void APowerUp::CollectibleBehaviour(AMarioCharacter* _mario)
{
	Save(_mario);
	SetLifeSpan(.1f);
	if (!_mario)
		return;
	_mario->AddPowerUp();
}
