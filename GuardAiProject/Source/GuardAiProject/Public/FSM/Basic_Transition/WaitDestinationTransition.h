// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "../MoveComponent.h"
#include "WaitDestinationTransition.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UWaitDestinationTransition : public UTransition
{
	GENERATED_BODY()
	
	TObjectPtr<UMoveComponent> move = nullptr;

public:
	virtual void InitTransition(class UFSMObject* _fsm) override;
	virtual bool IsValid() override;
};
