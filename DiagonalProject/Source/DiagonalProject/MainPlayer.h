// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Gameframework/SpringArmComponent.h"
#include "MainPlayer.generated.h"

UCLASS()
class DIAGONALPROJECT_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> cam = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> arm = nullptr;


#pragma region Input

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UInputMappingContext> context = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> moveAction = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> rotateArmAction = nullptr;




	UPROPERTY(EditAnywhere)
	float targetYaw;
	
	bool canRotate = false;
#pragma endregion


public:
	AMainPlayer();

protected:
	void InitInput();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	void Move(const FInputActionValue& _value);
	void StopRotate(const FInputActionValue& _value);
	float FindAngle(const FVector2D& _target);
	void Turn();

	void RotateArm(const FInputActionValue& _value);

};
