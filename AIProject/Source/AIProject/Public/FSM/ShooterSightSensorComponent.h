// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/SightSensorComponent.h"
#include "ShooterSightSensorComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AIPROJECT_API UShooterSightSensorComponent : public USightSensorComponent
{
	GENERATED_BODY()
	


protected:
	virtual void UpdateSight() override;

};
