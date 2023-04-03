// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SaveData.h"
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
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMove, float, _axis);

	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnMove onMove;
		UPROPERTY(EditAnywhere)
		TObjectPtr<USaveData> saveData = nullptr;
		FSnapShot marioSnap;
	bool isDead = false,
		hasPowerUp = false,
		startPowerUpEffect = false,
		startShrinkEffect = false;
		FTimerHandle respawnDelay;
		FVector initSize, powerUpTargetSize;
		float powerUpTimer = 0;
public:
	FORCEINLINE FOnMove& OnMove() { return onMove; }
	FORCEINLINE bool IsDead() const { return isDead; }
	FORCEINLINE bool GetPowerUp() const { return hasPowerUp; }
	FORCEINLINE void SetPowerUp(bool& _value) { hasPowerUp = _value; }
	void Die();
	void AddPowerUp();
	AMarioCharacter();
protected:
	virtual void BeginPlay() override;
	void ReloadDatas();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void OnRespawnDelayed();
	void PowerUpEffect();
	void ShrinkEffect();
};
