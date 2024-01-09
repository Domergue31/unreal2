// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/BasicStates/ShootState.h"
#include "FSM/FSMObject.h"
#include "FSM/BasicTransitions/WaitDestroyTransition.h"
#include "FSM/FSMComponent.h"

void UShootState::Enter(UFSMObject* _owner)
{
	Super::Enter(_owner);
	AActor* _bullet = GetWorld()->SpawnActor<AActor>(bulletRef, _owner->GetOwner()->GetOwner()->GetActorLocation() + _owner->GetOwner()->GetOwner()->GetActorForwardVector() * 100, _owner->GetOwner()->GetOwner()->GetActorRotation());
	_bullet->SetLifeSpan(bulletLifeTime);
	SetWaitDestroyTransition();
}

void UShootState::SetWaitDestroyTransition()
{
	for (TObjectPtr<UTransition> _transition : runningTransitions)
	{
		UWaitDestroyTransition* _tr = Cast<UWaitDestroyTransition>(_transition);
		if (_tr)
		{
			_tr->LaunchTimer(bulletLifeTime);
			return;
		}
	}
}
