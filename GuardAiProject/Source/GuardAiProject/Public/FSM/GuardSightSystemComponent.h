// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/SightSystemComponent.h"
#include "GuardSightSystemComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GUARDAIPROJECT_API UGuardSightSystemComponent : public USightSystemComponent
{
	GENERATED_BODY()
	
	virtual void UpdateSight() override;
};
