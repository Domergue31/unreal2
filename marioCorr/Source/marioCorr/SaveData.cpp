// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveData.h"
#include "MarioCharacter.h"


void USaveData::SavedCharacter(AMarioCharacter* _char)
{
	savePowerUp = _char->GetPowerUp();
}

void USaveData::LoadCharacter(AMarioCharacter* _char)
{
	_char->SetPowerUp(savePowerUp);
}
