// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spells.h"
#include "FireBall.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API UFireBall : public USpells
{
	GENERATED_BODY()
	
protected:
	virtual void Spawn(UWorld* _world, const FVector& _origin, const float& _yaw) override;
};
