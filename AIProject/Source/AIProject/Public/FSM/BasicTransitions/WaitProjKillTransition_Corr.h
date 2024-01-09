// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "WaitProjKillTransition_Corr.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UWaitProjKillTransition_Corr : public UTransition
{
	GENERATED_BODY()
	UPROPERTY() TObjectPtr<AActor> currentProjectile = nullptr;
public:
	void SendProjectile(TObjectPtr<AActor> _projectile);
	virtual bool IsValidTransition() override;
};
