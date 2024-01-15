// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/SightSensorComponent.h"
#include "Kismet/KismetSystemLibrary.h"

USightSensorComponent::USightSensorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USightSensorComponent::UpdateSight()
{
    FVector _offset = FVector(0, sightHeight, 0);
    FVector _origin = GetOwnerLocation() + _offset;
    if (targetSight)
    {
        DrawDebugLine(GetWorld(), GetOwnerLocation(), targetSight->GetActorLocation(), FColor::Yellow, false, -1, 0, 2);
        return;
    }
    FVector _to;
    for (int i = -(sightAngle / 2); i < sightAngle / 2; i += definition)
    {
        FHitResult _result;
        _to = (GetOwnerLocation() + FQuat::MakeFromEuler(FVector(0, i, 0)) * (GetOwner()->GetActorForwardVector() * range)) + (_offset * FMath::Sin(GetWorld()->TimeSeconds));
        bool _impact = UKismetSystemLibrary::LineTraceSingleForObjects(this, _origin, _to, layers, false, TArray<AActor*>(), EDrawDebugTrace::None, _result, false);
        DrawDebugLine(GetWorld(), _origin, _to, FColor::Magenta, false, -1, 0, 2);
        if (_impact)
        {
            targetSight = _result.GetActor();
            return;
        }
    }
}


void USightSensorComponent::BeginPlay()
{
	Super::BeginPlay();

}


void USightSensorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    UpdateSight();
}

