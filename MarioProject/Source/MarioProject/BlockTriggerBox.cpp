// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockTriggerBox.h"
#include "MarioProjectCharacter.h"

void ABlockTriggerBox::BeginPlay()
{
	if (!originalBlock)
		return;
	block = GetWorld()->SpawnActor<ABlock>(originalBlock, GetActorLocation(), GetActorRotation());
}

void ABlockTriggerBox::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char || !block)
		return;
	block->Active();
	this->SetActorHiddenInGame(true);
	Destroy();
}

void ABlockTriggerBox::NotifyActorEndOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char)
		return;
}
