// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class AIPROJECT_API UTransition : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<class UState> nextState = nullptr;

public:
	FORCEINLINE TSubclassOf<UState> GetState() const { return nextState; }
	virtual void InitTransition();
	virtual bool IsValidTransition();
};
