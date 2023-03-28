// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skills.h"
#include "StarFishSkill.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCORR_API UStarFishSkill : public USkills
{
	GENERATED_BODY()
public:
	virtual void Spawn(UWorld* _world, const FVector& _origin, const float& _yaw) override;
};
