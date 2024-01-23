// Fill out your copyright notice in the Description page of Project Settings.


#include "SightSystemComponent.h"


USightSystemComponent::USightSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void USightSystemComponent::BeginPlay()
{
	Super::BeginPlay();


}


void USightSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateSight();
}

void USightSystemComponent::UpdateSight()
{

}
