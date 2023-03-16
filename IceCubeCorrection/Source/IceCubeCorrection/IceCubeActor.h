
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utils.h"
#include "InputUtils.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/cameraComponent.h"
#include "ActorMovementCorrComponent.h"
#include "IceCubeActor.generated.h"

USTRUCT()
struct FIceCubeSettings
{
	GENERATED_BODY()

public:
	FVector initSize = FVector(1);
	FVector startScale;

	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float divideSizeBy = 3;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float meltingTime = 30;

private:
	float currentTime = 0;
public:
	FORCEINLINE float ScaleRatio() const { return currentTime / meltingTime; }
	FORCEINLINE FVector TargetSize() const { return initSize / divideSizeBy; }
	FORCEINLINE void UpdateScaleTimer(const UWorld* _world)
	{
		currentTime += _world->DeltaTimeSeconds;
		if (currentTime > meltingTime)
		{
			currentTime = meltingTime;
			return;
		}
	}
	FORCEINLINE void UpdateScale(AActor* _target)
	{
		_target->SetActorScale3D(FMath::Lerp(initSize, TargetSize(), ScaleRatio()));
	}
	FORCEINLINE void ResetScale(AActor* _target, float _factor)
	{
		currentTime = 0;
		_target->SetActorScale3D(FMath::Lerp(startScale, initSize, _factor));
	}
};


UCLASS()
class ICECUBECORRECTION_API AIceCubeActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UActorMovementCorrComponent> movement = nullptr;

	UPROPERTY(EditAnywhere)
		FIceCubeSettings settings;
	
public:	
	AIceCubeActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitIceCube();
	void BindInput();

	void ScaleBehaviour();
	UFUNCTION() void ResetIceSizeBehaviour(float _scale);
	void StartResetIce();

};
