// Fill out your copyright notice in the Description page of Project Settings.


#include "PathRunnerComponent.h"


void UPathRunnerComponent::Restart()
{
	index = 0;
	readSpeed = FMath::Abs(readSpeed);
}

UPathRunnerComponent::UPathRunnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

FVector UPathRunnerComponent::GetPoint()
{
	if (!currentPath) return FVector();
	return currentPath->GetAt(index)->GetActorLocation();;
}

void UPathRunnerComponent::SetIndexPrevious()
{
	if (index >= currentPath->Count() - 1 && readSpeed == -1 || index == 0 && readSpeed == 1)
		readSpeed = -readSpeed;
	index -= readSpeed;	
}

void UPathRunnerComponent::SetIndexNext()
{
	if (index >= currentPath->Count() - 1 && readSpeed == 1 || index == 0 && readSpeed == -1)
		readSpeed = -readSpeed;
	index += readSpeed;
}

