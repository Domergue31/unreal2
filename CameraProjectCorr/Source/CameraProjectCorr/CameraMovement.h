// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "CameraMovement.generated.h"

/**
 * 
 */
UCLASS(ABSTRACT)
class CAMERAPROJECTCORR_API ACameraMovement : public ACameraActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> target = nullptr;

#pragma region Debug
	UPROPERTY(EditAnywhere, Category="Debug")
	bool useDebug = true;
	UPROPERTY(EditAnywhere, Category="Debug")
	FColor validDebugColor = FColor::Green;
	UPROPERTY(EditAnywhere, Category="Debug")
	FColor noValidDebugColor = FColor::Red;
#pragma endregion
public:
	FORCEINLINE bool IsValid() const { return target != nullptr; }
	FORCEINLINE FVector CurrentPosition() const { return GetActorLocation(); }
	FORCEINLINE virtual FVector TargetPosition() const
	{
		if (!target)
			return FVector(0);
		return target->GetActorLocation();
	}
	FORCEINLINE virtual FVector FinalPosition() const { return TargetPosition() + Offset(); }
	FORCEINLINE virtual FVector Offset() const { return FVector(0); }
	ACameraMovement();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void UpdateCameraPosition();
	virtual void DrawDebug();
	virtual bool ShouldTickIfViewportsOnly() const override;
	FORCEINLINE FVector GetLocalOffset(const float& _x, const float& _y, const float& _z) const
	{
		return (target->GetActorForwardVector() * _x +
			target->GetActorRightVector() * _y +
			target->GetActorUpVector() * _z);
	}
};
