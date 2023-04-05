// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreManager.h"

void UScoreManager::ResetScore()
{
	score = 0;
	onAddScore.Broadcast(score);
}
