// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SaveData.h"
#include "SwitchData.h"
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
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJump, float, _axis);
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDie, float, _axis);

	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnMove onMove;
	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnJump onJump;
	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnDie onDie;

	UPROPERTY(EditAnywhere, BlueprintreadWrite, meta = (AllowPrivateAccess))
		TObjectPtr<USwitchData>  levelLoadData = nullptr;

		UPROPERTY(EditAnywhere)
		TObjectPtr<USaveData> saveData = nullptr;
		FSnapShot marioSnap;

		bool isDead = false,
			hasPowerUp = false,
			startPowerUpEffect = false,
			startShrinkEffect = false,
			isJumping = false;

		FTimerHandle respawnDelay;
		FVector initSize, powerUpTargetSize;
		FVector jumpLastLocation;
		float powerUpTimer = 0;

public:
	FORCEINLINE FOnMove& OnMove() { return onMove; }
	FORCEINLINE FOnJump& OnJump() { return onJump; }
	FORCEINLINE FOnDie& OnDie() { return onDie; }
	FORCEINLINE bool IsDead() const { return isDead; }
	FORCEINLINE bool GetPowerUp() const { return hasPowerUp; }
	FORCEINLINE bool GetStartShrinkEffect() const { return startShrinkEffect; }
	FORCEINLINE void SetPowerUp(bool& _value) { hasPowerUp = _value; }
	FORCEINLINE TObjectPtr<USaveData> SaveData() { return saveData; }
	void Die();
	void AddPowerUp();
	AMarioCharacter();
protected:
	virtual void BeginPlay() override;
	void ReloadDatas();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void QuitGame();
	void OnRespawnDelayed();
	void PowerUpEffect();
	void ShrinkEffect();
	void VerifyJump();
};
