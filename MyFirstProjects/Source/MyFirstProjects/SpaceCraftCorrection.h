// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Galaxy.h"
#include "SpaceCraftCorrection.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API ASpaceCraftCorrection : public AActor
{
	GENERATED_BODY()
	
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<AGalaxy> currentGalaxy = nullptr;
	UPROPERTY(EditAnywhere)
		float fwdWeight = 1;
	UPROPERTY(EditAnywhere)
		float rotateWeight = 1;
	UPROPERTY(EditAnywhere)
		float pitchWeight = 1;

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
};
