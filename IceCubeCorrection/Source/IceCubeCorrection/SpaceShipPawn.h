// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "LitleSpaceShip.h"
#include "SpaceShipPawn.generated.h"

USTRUCT()
struct FSpaceShipMovementSettings
{
	GENERATED_BODY()

	FVector shipVelocity;
	FRotator rotationVelocity;

	UPROPERTY(VisibleAnywhere)
		float fwdAxis;
	UPROPERTY(VisibleAnywhere)
		float yawAxis;
	UPROPERTY(VisibleAnywhere)
		float pitchAxis;
	UPROPERTY(EditAnywhere)
		float fwdWeight = 1;
	UPROPERTY(EditAnywhere)
		float rotateWeight = 2;

	UPROPERTY(EditAnywhere)
		float rotaSpeed = 10;
	UPROPERTY(EditAnywhere)
		float pitchSpeed = 5;
};

UCLASS()
class ICECUBECORRECTION_API ASpaceShipPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UFloatingPawnMovement> movement = nullptr;
	UPROPERTY(EditAnywhere)
		FSpaceShipMovementSettings settings;

	float rollAxis;
	float bankAngle = 45.0f, bankPitchAngle = 170.0f;

public:
	ASpaceShipPawn();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void RotatePitch(float _axis);
	void RotateRoll(float _axis);
};
