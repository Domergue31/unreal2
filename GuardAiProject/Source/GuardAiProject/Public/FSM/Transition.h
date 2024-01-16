// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GUARDAIPROJECT_API UTransition : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<class UState> nextState = nullptr;

	TObjectPtr<class UFSMObject> currentFSM = nullptr;
public:
	FORCEINLINE TSubclassOf<UState> NextState() const { return nextState; }
	virtual void InitTransition(class UFSMObject* _fsm);
	virtual bool IsValid();
};
