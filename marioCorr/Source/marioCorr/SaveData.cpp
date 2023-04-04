// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveData.h"
#include "MarioCharacter.h"
#include "MarioGameMode.h"


void USaveData::SavedCharacter(AMarioCharacter* _char)
{
	savePowerUp = _char->GetPowerUp();
	AMarioGameMode* _gm = Cast<AMarioGameMode>(_char->GetWorld()->GetAuthGameMode());
	if (!_gm)
		return;
	saveCoins = _gm->GetCoins()->GetCoins();
	saveScore = _gm->GetScore()->GetScore();
}

void USaveData::LoadCharacter(AMarioCharacter* _char)
{
	_char->SetPowerUp(savePowerUp);
	AMarioGameMode* _gm = Cast<AMarioGameMode>(_char->GetWorld()->GetAuthGameMode());
	if (!_gm)
		return;
	_gm->GetCoins()->AddCoins(saveCoins);
	_gm->GetScore()->AddScore(saveScore);
}
