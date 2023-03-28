// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets.h"
#include "Projectile.h"
#include "Skill.generated.h"

/**
 * 
 */
UCLASS()
class SPELLCORR_API USkill : public UDataAssets
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectile> projectileType;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		float lifeSpan = 5;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		float radius = 100;

	FVector GetSpawnLocation(const int& _angle, const float& _radius) const;
public:
	virtual void Spawn(const UWorld* _world, const FVector& _origin, const float& _yaw);
};
