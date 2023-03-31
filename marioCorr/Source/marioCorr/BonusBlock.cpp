// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusBlock.h"

void ABonusBlock::DownBehaviour(AMarioCharacter* _char)
{
	if (!bonusElement || !bonusBlockGraphics)
		return;
	GetWorld()->SpawnActor<AActor>(bonusBlockGraphics, GetActorLocation(), GetActorRotation());
	GetWorld()->SpawnActor<AActor>(bonusElement, GetActorLocation() + offsetSpawnBonus, GetActorRotation());
	SetLifeSpan(0.1);
}
