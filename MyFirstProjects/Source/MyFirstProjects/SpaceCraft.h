// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceCraft.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API ASpaceCraft : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
		float forwardSpeed = 50;
	UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
		float towardSpeed = 50;
	UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
		float rotationSpeed = 25;


	FRotator initRotation;
	FVector initLocation;

		UPROPERTY(EditAnywhere, Category = Space)
		TArray<TObjectPtr<AActor>> planets = {};

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
	void PitchRotation(float _axis);
	void RollRotation(float _axis);
	void ShowDebug();
	//void Rotation_Interp(FRotator _from, FRotator _to);
};
