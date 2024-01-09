// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.h"
#include "State.generated.h"

/**
 * 
 */

UCLASS(Abstract, Blueprintable)
class AIPROJECT_API UState : public UObject
{
	GENERATED_BODY()
	UPROPERTY() TObjectPtr<class UFSMObject> currentFSM = nullptr;
	UPROPERTY(EditAnywhere) TArray<TSubclassOf<UTransition>> transitions = {};
protected:
	UPROPERTY() TArray<TObjectPtr<UTransition>> runningTransitions = {};
public:
	virtual void Enter(class UFSMObject* _owner);
	virtual void Update();
	virtual void Exit();
	virtual void InitTransitions();
private:
	void CheckForValidTransition();
};
