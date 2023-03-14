// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Galaxy.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TimerComponent.h"
#include "SpaceCraftCorrection.generated.h"


USTRUCT()
struct FSpringArmMemory
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
		float armLenght = 0;
	UPROPERTY(VisibleAnywhere)
		FVector initLocation;


	FSpringArmMemory() {

	}
	FSpringArmMemory(USpringArmComponent* _spring)
	{
		armLenght = _spring->TargetArmLength;
		initLocation = _spring->SocketOffset;
	}
	void ResetValues(USpringArmComponent* _toWrite)
	{
		_toWrite->TargetArmLength = armLenght;
		_toWrite->SocketOffset = initLocation;
	}
	
};


USTRUCT()
struct FPassiveModeSettings
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, Category = "Passive settings", meta = (UIMin = 100, ClampMin = 100, UIMax = 1000, ClampMax = 1000))
		float minArmLenght = 300;
	UPROPERTY(EditAnywhere, Category = "Passive settings", meta = (UIMin = 100, ClampMin = 100, UIMax = 1000, ClampMax = 1000))
		float maxArmLenght = 500;

	UPROPERTY(EditAnywhere, Category = "Passive settings", meta = (UIMin = -500, ClampMin = -500, UIMax = 2000, ClampMax = 2000))
		float minHeight = -500;
	UPROPERTY(EditAnywhere, Category = "Passive settings", meta = (UIMin = -500, ClampMin = -500, UIMax = 2000, ClampMax = 2000))
		float maxHeight = 500;

	FORCEINLINE float GetRandomlenght() const
	{
		return FMath::FRandRange(minArmLenght, maxArmLenght);
	}
	FORCEINLINE float GetRandomHeight() const
	{
		return FMath::FRandRange(minHeight, maxHeight);
	}
};


UCLASS()
class MYFIRSTPROJECTS_API ASpaceCraftCorrection : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShipMovement, float, _axis);
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShipAxis);

		FOnShipMovement onShipMovement;
		FOnShipAxis onShipAxis;

		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<AGalaxy> currentGalaxy = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTimerComponent> customTimer = nullptr;


	UPROPERTY(EditAnywhere)
		float fwdWeight = 1;
	UPROPERTY(EditAnywhere)
		float rotateWeight = 1;
	UPROPERTY(EditAnywhere)
		float pitchWeight = 1;

	UPROPERTY(EditAnywhere)
		float passiveModeYawSpeed = 10;

	UPROPERTY(EditAnywhere)
		FPassiveModeSettings passiveModeSettings;
	UPROPERTY(EditAnywhere)
		FSpringArmMemory springSnapshot;

	bool isMoving = false;
	bool passiveModeEnable = false;
	FRotator initRotation;
	FVector shipVelocity;
	float forwardVelocity, rotateAxis, pitchAxis, bankAngle = 45;
	float speed = 2;

public:	
	ASpaceCraftCorrection();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;

	void InitShip();
	void InitInput();
	void MoveForward(float _axis);
	void RotateShip(float _axis);
	void AddFloatingBehaviour();
	void AddPitch(float _axis);
	void RotateAroundCamera();
	void SetRandomPassiveValues();
	UFUNCTION() void ResetCameraRotation();
	UFUNCTION() void PassiveModeEnable();
	UFUNCTION() void PassiveModeDisable();
	UFUNCTION() void MovingDetection(float _value);
};
