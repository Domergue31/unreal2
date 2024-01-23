// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BTEXO_API AProjectile : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) float speed = 100;
	UPROPERTY(EditAnywhere) int lifeTime = 5;
public:	
	AProjectile();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void Move();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
