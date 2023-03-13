// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planet.h"
#include "SpaceCraft.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API ASpaceCraft : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMove);

	UPROPERTY(EditAnywhere, Category = "Space|Speed", meta = (UIMin = 0, ClampMin = 0))
		float forwardSpeed = 200;
	UPROPERTY(EditAnywhere, Category = "Space|Speed", meta = (UIMin = 0, ClampMin = 0))
		float rotationSpeed = 150;
	UPROPERTY(EditAnywhere, Category = "Space|Speed", meta = (UIMin = 0, ClampMin = 0, UIMax = 5, ClampMax = 5))
		float towardRotationSpeed = 2.0f;

	UPROPERTY(VisibleAnywhere, Category = "Space|Speed")
		float velocity = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Space|Speed", meta = (UIMin = 0, ClampMin = 0))
		float accelerationSpeed = 3;


	FRotator initRotation;
	FVector initLocation;

	UPROPERTY(EditAnywhere, Category = "Space")
		TArray<TObjectPtr<AActor>> planets = {};

		UPROPERTY()
		TArray<FVector> planetsScale = {};

		FOnMove onMove;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	
public:	
	ASpaceCraft();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void SetUpInput();
	void MoveForward(float _axis);
	void MoveToward(float _axis);
	void MoveUp(float _axis);
	void RollRotation(float _axis);
	void TowardRotation_Interp(FRotator _from, FRotator _to, float _speed, float _axis);
	void Respawn();
	void ResetRotation();

	void ShowDebug();
	void InitPlanetsScale(const FVector& _location);
	UFUNCTION() void SetPlanetScale();
};
