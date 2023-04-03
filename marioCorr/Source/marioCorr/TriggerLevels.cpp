// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerLevels.h"
#include "MarioCharacter.h"

void ATriggerLevels::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioCharacter* mario = Cast<AMarioCharacter>(_other);
	if (!mario)
		return;
	levelLoadData->LoadLevel(GetWorld());
}
