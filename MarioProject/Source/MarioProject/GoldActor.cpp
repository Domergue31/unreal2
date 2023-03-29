// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldActor.h"
#include "MarioProjectCharacter.h"

AGoldActor::AGoldActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGoldActor::Init(const float& _lifeSpan, AMarioProjectCharacter* _char)
{
	SetLifeSpan(_lifeSpan);
	_char->AddGolds(1);

}

void AGoldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGoldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoldActor::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (_char)
	{
		_char->AddGolds(1);
		Destroy();
	}

}

