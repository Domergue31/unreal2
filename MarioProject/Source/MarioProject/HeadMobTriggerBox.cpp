// Fill out your copyright notice in the Description page of Project Settings.


#include "HeadMobTriggerBox.h"
#include "MarioProjectCharacter.h"

void AHeadMobTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHeadMobTriggerBox::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char || !mob)
		return;
	mob->Hit();
}

void AHeadMobTriggerBox::NotifyActorEndOverlap(AActor* _other)
{

}
