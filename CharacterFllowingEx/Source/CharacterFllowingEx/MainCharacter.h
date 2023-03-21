// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "FollowerComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class CHARACTERFLLOWINGEX_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, _axis);

	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnMoveForward onMoveForward;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UFollowerComponent> follow = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<AMainCharacter> follower = nullptr;
	UPROPERTY(EditAnywhere)
		bool isPossess = true;

public:
	AMainCharacter();
	FORCEINLINE FOnMoveForward& OnMoveForward() { return onMoveForward; }
	FORCEINLINE void SetIsPossessEnable() 
	{
		isPossess = true;
		GetWorld()->GetFirstPlayerController()->Possess(this);
	}
	FORCEINLINE bool GetIsPossess() { return isPossess; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void RotateYaw(float _axis);
	void ChangeFollow();
};
