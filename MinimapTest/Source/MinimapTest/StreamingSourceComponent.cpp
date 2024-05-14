// Fill out your copyright notice in the Description page of Project Settings.


#include "StreamingSourceComponent.h"
#include "StreamingSourceManagerSubsystem.h"
#include "MinimapTestGameMode.h"

UStreamingSourceComponent::UStreamingSourceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UStreamingSourceComponent::BeginPlay()
{
	Super::BeginPlay();
	//UStreamingSourceManagerSubsystem* _manager = GetWorld()->GetSubsystem<UStreamingSourceManagerSubsystem>();
	//_manager->Register(this);

	AMinimapTestGameMode* _gm = GetWorld()->GetAuthGameMode<AMinimapTestGameMode>();
	if (!_gm) return;
	id = FString::FromInt(_gm->GetStreamingSourceManager()->GetAll().Num());
	_gm->GetStreamingSourceManager()->Register(this);
}



void UStreamingSourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

