// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowerComponent.h"

UFollowerComponent::UFollowerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFollowerComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UFollowerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

