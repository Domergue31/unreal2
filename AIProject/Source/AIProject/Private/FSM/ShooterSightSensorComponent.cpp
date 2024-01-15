// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ShooterSightSensorComponent.h"
#include "MathUtils.h"
#include "Kismet/KismetSystemLibrary.h"

void UShooterSightSensorComponent::UpdateSight()
{
	TArray<FHitResult> _results;
	//TArray<AActor*> _actors;
	//UKismetSystemLibrary::SphereOverlapActors(this, GetSightOffsetLocation(), range, layers, nullptr, TArray<AActor*>(), _actors);
	UKismetSystemLibrary::SphereTraceMultiForObjects(this, GetSightOffsetLocation(), GetOwnerLocation(), range, layers, false, {GetOwner()}, EDrawDebugTrace::None, _results, false);

	const float _degToRadAngle = FMath::DegreesToRadians(sightAngle/2);
	DrawDebugCone(GetWorld(), GetOwnerLocation(), GetOwner()->GetActorForwardVector(), range * 1.4f, _degToRadAngle, _degToRadAngle, 10, TargetSight() ? FColor::Green : FColor::Red);
	
	for (size_t i = 0; i < _results.Num(); i++)
	{

		FVector _dir = (_results[i].GetActor()->GetActorLocation() - GetOwnerLocation()).GetSafeNormal();
		if (MathUtils::Angle(_dir, GetOwner()->GetActorForwardVector().GetSafeNormal()) < sightAngle / 2)
		{
			targetSight = _results[i].GetActor();
			return;
		}
	}
	targetSight = nullptr;
}
