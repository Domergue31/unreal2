#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Camera/CameraComponent.h>
#include "CameraSettings.h"
#include "CameraActorMovement.generated.h"



UCLASS()
class CAMERAPROJECT_API ACameraActorMovement : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Settings")
		TObjectPtr<UCameraComponent> camera = nullptr;


protected:
	UPROPERTY(EditAnywhere, Category="Settings")
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraSettings> cameraSettings = nullptr;
		


public:
	ACameraActorMovement();
	virtual FVector GetTargetLocation() const
	{
		if (!target)
			return FVector(0);
		return target->GetActorLocation();
	}
	virtual FVector GetFinalLocation()
	{
		return GetTargetLocation() + GetOffset();
	}
	virtual FVector GetOffset()
	{
		return FVector(0);
	}
	bool IsValid() const 
	{
		return target != nullptr;
	}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void UpdateCameraPosition();
	virtual void DrawDebug();

	FVector GetLocalOffset(const float& _x, const float& _y, const float& _z);
};
