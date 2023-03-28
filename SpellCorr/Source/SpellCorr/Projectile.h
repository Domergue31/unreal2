// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class SPELLCORR_API AProjectile : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		float projectileSpeed = 10;
public:	
	AProjectile();
	virtual void InitProjectile(const float& _lifeSpan);
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void Behaviour();
};
