// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/BasicTransitions/WaitTransition.h"

void UWaitTransition::InitTransition()
{
	GetWorld()->GetTimerManager().SetTimer(waitTimer, this, &UWaitTransition::Wait, waitTime, false);
}

bool UWaitTransition::IsValidTransition()
{
	return isDone;
}

void UWaitTransition::Wait()
{
	isDone = true;
}
