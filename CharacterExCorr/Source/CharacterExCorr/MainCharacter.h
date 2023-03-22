// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Gameframework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MainCharacter.generated.h"

USTRUCT()
struct FFollowersSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		float speed = 100;
	UPROPERTY(EditAnywhere)
		float minimalRange = 200;
	FORCEINLINE bool IsAtRange(const FVector& _from, const FVector& _to) const
	{
		return FVector::Distance(_from, _to) < minimalRange;
	}
};



UCLASS()
class CHARACTEREXCORR_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, _axis);

	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnMoveForward onMoveForward;

	UPROPERTY(EditAnywhere)
		FFollowersSettings settings;
	bool isControl = false;
public:
	AMainCharacter();
	FORCEINLINE FOnMoveForward& OnMoveForward() { return onMoveForward; }
	FORCEINLINE void SetControl(const bool& _value) { isControl = _value; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
	void FollowBehaviour();
};
