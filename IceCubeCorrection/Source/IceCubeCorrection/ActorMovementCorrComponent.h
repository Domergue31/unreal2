
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorMovementCorrComponent.generated.h"

USTRUCT()
struct FMovementSettings
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		float forwardAxis;
	UPROPERTY(VisibleAnywhere)
		float horizontalAxis;
	UPROPERTY(VisibleAnywhere)
		float rotateAxis;
	UPROPERTY(VisibleAnywhere)
		float forwardWeight = 1;
	UPROPERTY(VisibleAnywhere)
		float horizontalWeight = 1;
	UPROPERTY(VisibleAnywhere)
		float rotateWeight = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float timeToReset = 10;

private:
	float currentTimer;
public:
	FVector initLocation, currentLocation;
	FORCEINLINE float GetResetRatio() const { return currentTimer / timeToReset; }
	FORCEINLINE bool UpdateTimer(const UWorld* _world)
	{
		currentTimer += _world->DeltaTimeSeconds;
		if (currentTimer > timeToReset)
		{
			currentTimer = 0;
			return true;
		}
		return false;
	}
	FORCEINLINE void ResetValues()
	{
		forwardAxis = 0;
		horizontalAxis = 0;
		rotateAxis = 0;
	}
};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBECORRECTION_API UActorMovementCorrComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResetMovement, float, _ratio);
		FOnResetMovement onResetMovement;


		UPROPERTY(editAnywhere)
		FMovementSettings settings;

	bool isInResetStatus = false;

public:	
	UActorMovementCorrComponent();
	FORCEINLINE FOnResetMovement OnResetMoveent() { return onResetMovement; }
	FORCEINLINE FVector GetVelocity() const
	{
		return GetOwner()->GetActorForwardVector() * settings.forwardAxis + GetOwner()->GetActorRightVector() * settings.horizontalAxis;
	}
	FORCEINLINE FRotator GetRotationVelocity() const
	{
		return FRotator(0, settings.rotateAxis, 0);
	}
	FORCEINLINE void UpdateForwardWeight(const float& _value) { settings.forwardWeight = _value; }
	FORCEINLINE void UpdateHorizontalWeight(const float& _value) { settings.horizontalWeight = _value; }
	FORCEINLINE void UpdateRotateWeight(const float& _value) { settings.rotateWeight = _value; }
	void MoveForward(float _axis);
	void MoveHorizontal(float _axis);
	void Rotate(float _axis);
	void CallReset();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void UpdateMovement();
	void UpdateRotation();
	void ResetBehaviour();
	void OnEndReset();
};
