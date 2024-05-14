// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/SightSystemComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

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
    FVector _offset = FVector(0, sightData->GetSightHeight(), 0);
    if (targetSight)
    {
        DrawDebugLine(GetWorld(), GetOwnerLocation(), targetSight->GetActorLocation(), FColor::Yellow, false, -1, 0, 2);
        return;
    }
    FVector _to;
    for (int i = -(sightData->GetSightAngle() / 2); i < sightData->GetSightAngle() / 2; i += sightData->GetDefinition())
    {
        FHitResult _result;
        _to = (GetOwnerLocation() + FQuat::MakeFromEuler(FVector(0, i, 0)) * (GetOwner()->GetActorForwardVector() * sightData->GetRange())) + (_offset * FMath::Sin(GetWorld()->TimeSeconds));
        bool _impact = UKismetSystemLibrary::LineTraceSingleForObjects(this, GetSightHeightLocation(), _to, sightData->GetLayers(), false, TArray<AActor*>(), EDrawDebugTrace::None, _result, false);
        DrawDebugLine(GetWorld(), GetSightHeightLocation(), _to, FColor::Magenta, false, -1, 0, 2);
        if (_impact)
        {
            targetSight = _result.GetActor();
            return;
        }
    }
}

void USightSystemComponent::ClearSight()
{
	targetSight = nullptr;
}

