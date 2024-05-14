// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "RecordCamera.generated.h"

/**
 * 
 */
UCLASS()
class MINIMAPTEST_API ARecordCamera : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneCaptureComponent2D> captureComponent = nullptr;
	UPROPERTY(EditAnywhere)
	FString name = "CaptureCamera";
	UPROPERTY(EditAnywhere)
	bool isLerp = true;
	UPROPERTY(EditAnywhere)
	bool canMove = true;
	UPROPERTY(EditAnywhere)
	float speed = 100;

	UPROPERTY(VisibleAnywhere)
	FVector destination;


public:
	FORCEINLINE bool IsAtDestination() const { return FVector::Distance(GetActorLocation(), destination) <= 10;}
	ARecordCamera();

	void SetDestination(const FVector _destination);
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void Move();
};
