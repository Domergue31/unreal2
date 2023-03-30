// Fill out your copyright notice in the Description page of Project Settings.


#include "FlamesFlower.h"
#include "MarioProjectCharacter.h"

AFlamesFlower::AFlamesFlower()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFlamesFlower::BeginPlay()
{
	Super::BeginPlay();
}

void AFlamesFlower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFlamesFlower::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (!_char)
		return;
	if (!fireBall)
		return;
	_char->SetSpell(fireBall);
	this->Destroy();
}
