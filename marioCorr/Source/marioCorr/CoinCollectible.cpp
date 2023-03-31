// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinCollectible.h"

void ACoinCollectible::RotateCoin()
{
	AddActorWorldRotation(FRotator(0, rotateSpeed, 0));
}

void ACoinCollectible::Tick(float _delta)
{
	Super::Tick(_delta);
	RotateCoin();
}

void ACoinCollectible::CollectibleBehaviour(AMarioCharacter* _mario)
{
	SetLifeSpan(.1f);
}
