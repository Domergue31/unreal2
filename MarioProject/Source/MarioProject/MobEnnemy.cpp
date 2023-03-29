// Fill out your copyright notice in the Description page of Project Settings.


#include "MobEnnemy.h"

AMobEnnemy::AMobEnnemy()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMobEnnemy::BeginPlay()
{
	Super::BeginPlay();
	actualLife = settings->GetLife();
}

void AMobEnnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMobEnnemy::NotifyActorBeginOverlap(AActor* _other)
{
}

void AMobEnnemy::Hit()
{
}

