// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockTriggerBox.h"
#include "MarioProjectCharacter.h"





void ABlockTriggerBox::BeginPlay()
{
	block->OnBreak().AddDynamic(this, &ABlockTriggerBox::Break);
}


void ABlockTriggerBox::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char || !block)
		return;
	block->Active();
}

void ABlockTriggerBox::NotifyActorEndOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char)
		return;
}

void ABlockTriggerBox::Break()
{
	this->Destroy();
}
