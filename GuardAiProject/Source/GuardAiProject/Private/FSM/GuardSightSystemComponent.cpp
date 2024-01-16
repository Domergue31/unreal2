// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/GuardSightSystemComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../../MathUtils.h"

void UGuardSightSystemComponent::UpdateSight()
{
	TArray<AActor*> _actors = {};
	UKismetSystemLibrary::SphereOverlapActors(this, GetSightHeightLocation(), range, layers, nullptr, TArray<AActor*>(), _actors);
	DrawDebugSphere(GetWorld(), GetSightHeightLocation(), range, 20, FColor::White, false, -1, 0, 2);

	const float _deg2RadAngle = FMath::DegreesToRadians(sightAngle / 2);
	DrawDebugCone(GetWorld(), GetSightHeightLocation(), GetOwner()->GetActorForwardVector(), range * 1.4f, _deg2RadAngle, _deg2RadAngle, 10, TargetSight() ? FColor::Green : FColor::Red);

	for (size_t i = 0; i < _actors.Num(); i++)
	{
		FVector _dir = (_actors[i]->GetActorLocation() - GetOwnerLocation()).GetSafeNormal();
		if (MathUtils::Angle(GetOwner()->GetActorForwardVector().GetSafeNormal(), _dir) < sightAngle / 2)
		{
			targetSight = _actors[i];
			return;
		}
	}
	targetSight = nullptr;
}
