// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectiles.generated.h"

UCLASS()
class MARIOPROJECT_API AProjectiles : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		float projectilesSpeed = 100;
	bool destroy = false;
public:	
	AProjectiles();
	void InitProjectile(const float& _lifeSpan);
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other);
	void Behaviour();
	void IsDestroy();
};
