// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"
#include "MarioGameMode.h"
#include "MarioGameInstance.h"

void APowerUp::Save(AMarioCharacter* _mario)
{
	UMarioGameInstance* _gi = GetWorld()->GetGameInstance<UMarioGameInstance>();
	if (!_gi)
		return;
	_gi->GetScore()->AddScore(1000);
}

void APowerUp::CollectibleBehaviour(AMarioCharacter* _mario)
{
	Save(_mario);
	SetLifeSpan(.1f);
	if (!_mario)
		return;
	_mario->AddPowerUp();
}
