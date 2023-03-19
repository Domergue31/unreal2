// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerComponent.h"
#include "Utils.h"
#include "InputUtils.h"

UTimerComponent::UTimerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


UFUNCTION() void UTimerComponent::ResetTimer()
{
	timer = 0;
	isStarted = true;
}

void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateTimer(timer, maxTimer);
}

void UTimerComponent::UpdateTimer(float& _timer, const float& _max)
{
	if (!isStarted)
		return;
	_timer += DELTATIME;
	LOG_W(LogTemp, "%f", _timer)
	if (_timer >= _max)
	{
		onTimerEnd.Broadcast();
		_timer = 0;
		isStarted = false;
	}
}

