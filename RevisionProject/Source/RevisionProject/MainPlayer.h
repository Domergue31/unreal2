// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "CustomCameraActor.h"
#include "InputMappingContext.h"
#include "MainPlayer.generated.h"

UCLASS()
class REVISIONPROJECT_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> fpsCamera = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> tpsCamera = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> arm = nullptr;

#pragma region Inputs
	UPROPERTY(EditAnywhere, Category = "PlayerInputs")
	TSoftObjectPtr<UInputMappingContext> context = nullptr;
	UPROPERTY(EditAnywhere, Category = "PlayerInputs")
	TObjectPtr<UInputAction> moveVertical = nullptr;
	UPROPERTY(EditAnywhere, Category = "PlayerInputs")
	TObjectPtr<UInputAction> moveHorizontal = nullptr;
	UPROPERTY(EditAnywhere, Category = "PlayerInputs")
	TObjectPtr<UInputAction> rotateYaw = nullptr;
	UPROPERTY(EditAnywhere, Category = "PlayerInputs")
	TObjectPtr<UInputAction> rotatePitch = nullptr;
#pragma endregion

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (UIMin = 1, ClampMin = 1)) float verticalSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (UIMin = 1, ClampMin = 1)) float horizontalSpeed = 100;



public:
	AMainPlayer();

protected:
	void InitInputs();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void MoveVertical(const FInputActionValue& _value);
	void MoveHorizontal(const FInputActionValue& _value);
	void RotateYaw(const FInputActionValue& _value);
	void RotateCameraPitch(const FInputActionValue& _value);

};
