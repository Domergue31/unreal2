// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/BasicTransitions/WaitDestroyTransition.h"

void UWaitDestroyTransition::LaunchTimer(float _time)
{
	GetWorld()->GetTimerManager().SetTimer(waitDestroyTimer, this, &UWaitDestroyTransition::Destroy, _time, false);
}

bool UWaitDestroyTransition::IsValidTransition()
{
	return isDone;
}

void UWaitDestroyTransition::Destroy()
{
	isDone = true;
}
