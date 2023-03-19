// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GridComponent.h"
#include "GridFollowerActor.h"
#include "GridPawn.generated.h"

UCLASS()
class ICECUBECORRECTION_API AGridPawn : public APawn
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
        AGridFollowerActor* follower = nullptr;
public:
	AGridPawn();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
};
