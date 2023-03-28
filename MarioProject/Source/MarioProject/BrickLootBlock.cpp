// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickLootBlock.h"

ABrickLootBlock::ABrickLootBlock()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABrickLootBlock::Active()
{
	currenttouch++;
	if (currenttouch == maxTouch)
		SetLifeSpan(0.1f);
}

void ABrickLootBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABrickLootBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

