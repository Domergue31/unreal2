// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"

void APowerUp::CollectibleBehaviour(AMarioCharacter* _mario)
{
	SetLifeSpan(.1f);
	if (!_mario)
		return;
	_mario->AddPowerUp();
}
