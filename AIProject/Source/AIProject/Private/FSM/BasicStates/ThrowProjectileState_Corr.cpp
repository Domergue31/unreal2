// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/BasicStates/ThrowProjectileState_Corr.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"

void UThrowProjectileState_Corr::Enter(UFSMObject* _owner)
{
	Super::Enter(_owner);
	if (!projectile)
		return;
	FVector _loc = _owner->GetOwner()->GetOwner()->GetActorLocation() + _owner->GetOwner()->GetOwner()->GetActorForwardVector() * 150;
	AActor* _projectile = GetWorld()->SpawnActor<AActor>(projectile, _loc, FRotator(0));
	_projectile->SetLifeSpan(2);
	if (waitForKill)
		waitForKill->SendProjectile(_projectile);
}

void UThrowProjectileState_Corr::InitTransitions()
{
	Super::InitTransitions();
	for (size_t i = 0; i < runningTransitions.Num(); i++)
	{
		UWaitProjKillTransition_Corr* _wait = Cast<UWaitProjKillTransition_Corr>(runningTransitions[i]);
		if (_wait)
		{
			waitForKill = _wait;
			return;
		}
	}
}
