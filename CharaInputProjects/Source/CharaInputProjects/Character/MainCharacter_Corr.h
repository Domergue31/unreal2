// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interact/InteractComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "InputConfig.h"
#include "MainCharacter_Corr.generated.h"

UCLASS()
class CHARAINPUTPROJECTS_API AMainCharacter_Corr : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> arm = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere, Category="Interaction")
	TObjectPtr<UInteractComponent> interact = nullptr;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputConfig> inputsConfig = nullptr;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UCurveFloat> responseCurve = nullptr;
	UPROPERTY(EditAnywhere, Category="Movement")
	float rotationSpeed = 15;

	float TimeX = 0;
	float axis = 0;
public:
	AMainCharacter_Corr();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(const FInputActionValue& _value);
	void ReleaseForward(const FInputActionValue& _value);
	void RotateCharacter(const FInputActionValue& _value);
};
