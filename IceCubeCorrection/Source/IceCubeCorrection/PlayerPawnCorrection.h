// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GridActor.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "TimerComponent.h"
#include "Utils.h"
#include "PlayerPawnCorrection.generated.h"

USTRUCT()
struct FDemoSettings
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDemoMoveEnd);

	FOnDemoMoveEnd onDemoMoveEnd;

	UPROPERTY(EditAnywhere)
		bool isDemoMode = true;

	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int moveNumber = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int maxMoveNumber = 1;
	UPROPERTY()
		TArray<FVector> directions = { FVector(1, 0, 0),
									   FVector(-1, 0, 0),
									   FVector(0, 1, 0),
									   FVector(0, -1, 0), };

public:
	FORCEINLINE FVector GetDirection() 
	{
		int _direction = FMath::FRandRange(0, 4);
		return directions[_direction];
	}
	FORCEINLINE int GetMaxMoveNumber()
	{
		int _number = FMath::FRandRange(1, 7);
		return _number;
	}
};



UCLASS()
class ICECUBECORRECTION_API APlayerPawnCorrection : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTimerComponent> demoTimer = nullptr;
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<AGridActor> grid = nullptr;

	UPROPERTY(EditAnywhere)
		FDemoSettings demo;
public:
	APlayerPawnCorrection();

protected:
	void InitPawn();
	TObjectPtr<AGridActor> GetGrid() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void UpMove();
	void DownMove();
	void LeftMove();
	void RightMove();
	void SelectGridCell();
	UFUNCTION() void DemoMode();
	void StartDemo();
};
