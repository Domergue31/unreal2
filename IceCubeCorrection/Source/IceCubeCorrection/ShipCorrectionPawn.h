// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GridComponent.h"
#include "ShipCorrectionPawn.generated.h"

USTRUCT()
struct FShipControlsSettings
{
    GENERATED_BODY()

        UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
        float forwardWeight = 1;
    UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
        float rollWeight = 1;
    UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
        float yawWeight = 1;
    UPROPERTY(EditAnywhere, meta = (UIMin = -65, ClampMin = -65, UIMax = 65, ClampMax = 65))
        float maxAngle = 60;

    UPROPERTY(EditAnywhere)
        float forwardAxis;
    UPROPERTY(EditAnywhere)
        float rollAxis;
    UPROPERTY(EditAnywhere)
        float yawAxis;
};


UCLASS()
class ICECUBECORRECTION_API AShipCorrectionPawn : public APawn
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
        TObjectPtr<UGridComponent> grid = nullptr;


    UPROPERTY(EditAnywhere)
        FShipControlsSettings settings;

public:
	AShipCorrectionPawn();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    void MoveForward(float _axis);
    void RollMovement(float _axis);
    void YawMovement(float _axis);
};
