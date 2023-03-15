// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerComponent.h"
#include "Utils.h"


UTimerComponent::UTimerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}



void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateTimer(timer, timerMax);
}

void UTimerComponent::UpdateTimer(float& _timer, const float& _max)
{
	if (!isStarted)
		return;
	_timer += DELTATIME;
	onTimerChange.Broadcast();
	if (_timer >= _max)
	{
		onTimerEnd.Broadcast();
		_timer = 0;
		isStarted = false;
	}
}

void UTimerComponent::ResetTimer()
{
	timer = 0;
	isStarted = true;
}

