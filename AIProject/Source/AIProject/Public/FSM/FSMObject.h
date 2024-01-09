// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "UObject/NoExportTypes.h"
#include "FSMObject.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class AIPROJECT_API UFSMObject : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<UState> startingState = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<UState> currentState = nullptr;
	UPROPERTY() TObjectPtr<class UFSMComponent> owner = nullptr;
public:
	FORCEINLINE TObjectPtr<UFSMComponent> GetOwner() const { return owner; }
	virtual void StartFSM(UFSMComponent* _owner);
	virtual void SetNextState(TSubclassOf<UState> _state);
	virtual void UpdateFSM();
	virtual void StopFSM();
};
