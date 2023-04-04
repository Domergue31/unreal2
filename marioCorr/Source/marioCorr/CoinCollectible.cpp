// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinCollectible.h"
#include "MarioGameMode.h"

void ACoinCollectible::RotateCoin()
{
	AddActorWorldRotation(FRotator(0, rotateSpeed, 0));
}

void ACoinCollectible::Save(AMarioCharacter* _mario)
{
	AMarioGameMode* _gm = Cast<AMarioGameMode>(GetWorld()->GetAuthGameMode());
	if (!_gm)
		return;
	_gm->GetCoins()->AddCoins(1);
	_gm->GetScore()->AddScore(200);
	_mario->SaveData()->SavedCharacter(_mario);
}

void ACoinCollectible::Tick(float _delta)
{
	Super::Tick(_delta);
	RotateCoin();
}

void ACoinCollectible::CollectibleBehaviour(AMarioCharacter* _mario)
{
	Save(_mario);
	SetLifeSpan(.1f);
}
