// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameMode.h"

void AMarioGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	coins = NewObject<UCoinManager>(this);
	score = NewObject<UScoreManager>(this);
}
