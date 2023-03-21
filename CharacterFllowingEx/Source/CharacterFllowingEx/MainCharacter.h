// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class CHARACTERFLLOWINGEX_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<AMainCharacter> follower = nullptr;
	UPROPERTY(EditAnywhere)
		bool isFollowing = false;

public:
	AMainCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void RotateYaw(float _axis);
	void ChangeFollow();
};
