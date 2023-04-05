// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioTimerManager.h"

void UMarioTimerManager::TickProgress()
{
	tickProgress--;
	tickProgress = tickProgress < 0 ? 0 : tickProgress;
	onTimerProgress.Broadcast(tickProgress);
}

void UMarioTimerManager::StartTimer(UWorld* _world)
{
	_world->GetTimerManager().SetTimer(timer, this, &UMarioTimerManager::TickProgress, 1, true);
	tickProgress = maxTime;
}

void UMarioTimerManager::StopTimer(UWorld* _world)
{
	_world->GetTimerManager().PauseTimer(timer);
}

void UMarioTimerManager::RestartTimer(UWorld* _world)
{
	StopTimer(_world);
	tickProgress = maxTime;
	StartTimer(_world);
}
