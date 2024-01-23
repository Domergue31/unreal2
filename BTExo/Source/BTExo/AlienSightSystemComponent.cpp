// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienSightSystemComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MathUtils.h"

void UAlienSightSystemComponent::UpdateSight()
{
	TArray<AActor*> _actor;
	UKismetSystemLibrary::SphereOverlapActors(GetOwner(), GetSightHeightLocation(), range, layerMask, nullptr, {}, _actor);
	DrawDebugSphere(GetWorld(), GetSightHeightLocation(), range, 20, FColor::White, false, -1, 0, 2);

	const float _deg2RadAngle = FMath::DegreesToRadians(sightAngle / 2);
	DrawDebugCone(GetWorld(), GetSightHeightLocation(), GetOwner()->GetActorForwardVector(), range * 1.4f, _deg2RadAngle, _deg2RadAngle, 10, targetSight ? FColor::Green : FColor::Red, false, -1, 0, 2);

	for (size_t i = 0; i < _actor.Num(); i++)
	{
		FVector _dir = (_actor[i]->GetActorLocation() - GetOwner()->GetActorLocation()).GetSafeNormal();
		if (MathUtils::Angle(_dir, GetOwner()->GetActorForwardVector()) <= sightAngle / 2)
		{
			targetSight = _actor[i];
			return;
		}
	}
	targetSight = nullptr;
}
