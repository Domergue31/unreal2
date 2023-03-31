// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MarioCharacter.generated.h"

USTRUCT()
struct FSnapShot
{
	GENERATED_BODY()
	FVector location;
	FRotator rotation;
public:
	FSnapShot()
	{

	}
	FSnapShot(FTransform _transform)
	{
		location = _transform.GetLocation();
		rotation = _transform.GetRotation().Rotator();
	}
	void Reload(AActor* _actor)
	{
		_actor->SetActorLocationAndRotation(location, rotation);
	}
};


UCLASS()
class MARIOCORR_API AMarioCharacter : public ACharacter
{
	GENERATED_BODY()
		FSnapShot marioSnap;
		bool isDead = false;
		FTimerHandle respawnDelay;
public:
	FORCEINLINE bool IsDead() const { return isDead; }
	void Die();
	AMarioCharacter();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void OnRespawnDelayed();
};
