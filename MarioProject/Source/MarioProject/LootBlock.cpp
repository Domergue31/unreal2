// Fill out your copyright notice in the Description page of Project Settings.


#include "LootBlock.h"

ALootBlock::ALootBlock()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ALootBlock::BeginPlay()
{
}

void ALootBlock::Tick(float DeltaTime)
{
}

void ALootBlock::Used()
{
	used = true;
	mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialMaterial.TutorialMaterial'")));
}

void ALootBlock::Active()
{
	if (used)
		return;
	actualTouch++;
	if (actualTouch == maxTouch)
	{
		Used();
		AElements* _powerUp = GetWorld()->SpawnActor<AElements>(element, GetActorLocation() + FVector(0, 0, 100), GetActorRotation());
		Break();
		onBreak.Broadcast();
	}
}