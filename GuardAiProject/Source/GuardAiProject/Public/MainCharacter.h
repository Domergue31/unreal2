// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class GUARDAIPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMove, float, _axis);


	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnMove onMove;


	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere)  float moveSpeed = 10;
	UPROPERTY(EditAnywhere)  float rotateSpeed = 10;


#pragma region inputs
	UPROPERTY(EditAnywhere) TSoftObjectPtr<UInputMappingContext> context = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> move = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> rotateYaw = nullptr;
#pragma endregion


public:
	AMainCharacter();
	FORCEINLINE FOnMove& OnMove() { return onMove; }
protected:
	void InitInput();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void Move(const FInputActionValue& _value);
	void RotateYaw(const FInputActionValue& _value);
};
