// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skills.h"
#include "ArceusSkill.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCORR_API UArceusSkill : public USkills
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		int angleOffset = 90;
	UPROPERTY(EditAnywhere)
		int angleDefinition = 10;
public:
	virtual void Spawn(UWorld* _world, const FVector& _origin, const float& _yaw) override;
};
