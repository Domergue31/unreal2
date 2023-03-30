// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperMushroom.h"
#include "Block.h"
#include "MarioProjectCharacter.h"

ASuperMushroom::ASuperMushroom()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASuperMushroom::BeginPlay()
{
	Super::BeginPlay();
}

void ASuperMushroom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset((GetActorForwardVector() * direction) * GetWorld()->DeltaTimeSeconds * speed);
}

void ASuperMushroom::NotifyActorBeginOverlap(AActor* _other)
{
	ABlock* _block = Cast<ABlock>(_other);
	if (_block)
		ChangeDirection();
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char)
		return;
	_char->Healing();
	this->Destroy();
}

void ASuperMushroom::ChangeDirection()
{
	direction = -direction;
}
