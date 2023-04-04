// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleBlock.h"
#include "MarioGameMode.h"

void ADestructibleBlock::Save(AMarioCharacter* _mario)
{
	AMarioGameMode* _gm = Cast<AMarioGameMode>(GetWorld()->GetAuthGameMode());
	if (!_gm)
		return;
	_gm->GetScore()->AddScore(50);
	_mario->SaveData()->SavedCharacter(_mario);
}

void ADestructibleBlock::DownBehaviour(AMarioCharacter* _char)
{
	Save(_char);
	SetLifeSpan(0.1f);
}
