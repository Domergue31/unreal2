// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomWorldSettings.h"
#include "MinimapTestGameMode.h"

void ACustomWorldSettings::BeginPlay()
{
	if (HasAuthority() && subLevels.Contains(temp_currentWeather))
	{
		FName _levelName = FName(subLevels[temp_currentWeather]->GetName());
		AMinimapTestGameMode* _gm = GetWorld()->GetAuthGameMode<AMinimapTestGameMode>();
		if (!_gm) return;
		_gm->LoadLevel(_levelName);
	}
}
