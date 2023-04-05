// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameInstance.h"

void UMarioGameInstance::Init()
{
	Super::Init();
	coins = NewObject<UCoinManager>(this);
	score = NewObject<UScoreManager>(this);
	timer = NewObject<UMarioTimerManager>(this, timerRef);
	timer->StartTimer(GetWorld());
}
