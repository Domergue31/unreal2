// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/State.h"
#include "ResearchState.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UResearchState : public UState
{
	GENERATED_BODY()
	
public:
	virtual void Enter(UFSMObject* _fsm);

};
