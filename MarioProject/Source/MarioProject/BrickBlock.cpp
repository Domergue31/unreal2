// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickBlock.h"

ABrickBlock::ABrickBlock()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABrickBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABrickBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrickBlock::Active()
{
	actualTouch++;
	if (actualTouch == maxTouch)
	{
		Break();
		onBreak.Broadcast();
	}
}

