// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "../GuardSightSystemComponent.h"
#include "LoseDetectionTransition.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API ULoseDetectionTransition : public UTransition
{
	GENERATED_BODY()
	
	TObjectPtr<UGuardSightSystemComponent> sight = nullptr;

public:
	virtual void InitTransition(class UFSMObject* _fsm) override;
	virtual bool IsValid() override;
};
