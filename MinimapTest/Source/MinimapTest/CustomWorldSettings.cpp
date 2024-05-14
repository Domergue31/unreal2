// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomWorldSettings.h"
#include "Kismet/GameplayStatics.h"

void ACustomWorldSettings::BeginPlay()
{
	if (HasAuthority() && subLevels.Contains(temp_currentWeather))
	{
		FName _levelName = FName(subLevels[temp_currentWeather]->GetName());
		LoadLevel(_levelName);
	}
}



void ACustomWorldSettings::LoadLevel(const FName& _nameLevel)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, _nameLevel, true, false, LatentInfo);
}

void ACustomWorldSettings::UnloadLevel(const FName& _nameLevel)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::UnloadStreamLevel(this, _nameLevel, LatentInfo, true);
}
