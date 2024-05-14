// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../GuardSightSystemComponent.h"
#include "FSM/Transition.h"
#include "DetectTransition.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UDetectTransition : public UTransition
{
	GENERATED_BODY()

	TObjectPtr<UGuardSightSystemComponent> sight = nullptr;

public:
	virtual void InitTransition(class UFSMObject* _fsm) override;
	virtual bool IsValid() override;

};
