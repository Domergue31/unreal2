// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "WaitForTransition.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UWaitForTransition : public UTransition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (UMin = 1, ClampMin = 1, UMax = 20, CampMax = 20, EditCondition = "!randomTime")) int time = 2;

	UPROPERTY(EditAnywhere) bool randomTime = false;

	UPROPERTY(EditAnywhere, meta = (UMin = 1, ClampMin = 1, UMax = 20, CampMax = 20, EditCondition = "randomTime")) int minTime = 2;
	UPROPERTY(EditAnywhere, meta = (UMin = 1, ClampMin = 1, UMax = 20, CampMax = 20, EditCondition = "randomTime")) int maxTime = 6;



	bool isDone = false;
	FTimerHandle timer;
public:
	virtual void InitTransition(class UFSMObject* _fsm) override;
	virtual bool IsValid() override;
	void Wait();
};