// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Projectiles.h"
#include "Spells.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API USpells : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectiles> projectile = nullptr;
	UPROPERTY(EditAnywhere)
		float radius = 100;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int number = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0.1f, ClampMin = 0.1f))
		float lifeSpan = 5;

	FVector GetSpawnLocation(const float& _angle, const float& _radius) const;
	FORCEINLINE float GetPartRadius() { return radius / number; }
	FORCEINLINE float GetRadiusProgress(const int& _part) { return ((GetPartRadius() * _part) / radius) * 100; }
public:
	virtual void Spawn(UWorld* _world, const FVector& _origin, const float& _yaw);
};
