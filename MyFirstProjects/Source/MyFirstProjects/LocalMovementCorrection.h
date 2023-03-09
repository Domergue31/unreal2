

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocalMovementCorrection.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API ALocalMovementCorrection : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndTimer);


		UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
		float speed = 100;
		UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
			float rotateSpeed = 1;

		UPROPERTY(EditAnywhere, Category = Movement)
			bool canMove = true;
		UPROPERTY(EditAnywhere, Category = Movement)
			bool canRotate = true;

		UPROPERTY(EditAnywhere, Category = Movement)
			float scaleSpeed = 1;

	UPROPERTY(EditAnyWhere, Category = Timer, meta = (UIMin = 0, ClampMin = 0))
		float MaxTimeDelay = 10;

	float timer = 0;
	bool timerStarted = true;
	FVector initScale;

	FOnEndTimer onEndTimer;

		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	
public:	
	ALocalMovementCorrection();

	void InitObject();
	FORCEINLINE void SetCanMove(const bool& _value) { canMove = _value; }
	FORCEINLINE void SetCanRotate(const bool& _value) { canRotate = _value; }
	FORCEINLINE bool GetEndTimer() const { return timer > MaxTimeDelay; }
	FORCEINLINE float GetTimerProgress() const { return timer / MaxTimeDelay; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DebugAxis();
	void Move(const FVector& _direction, const float& _speed);
	void Rotate(const FRotator& _rotation, const float& _speed);
	void BreathOfTheScale(const float& _scaleSpeed);
	UFUNCTION() void StopMovement();
	UFUNCTION() void StopRotation();
	void UpdateTimer(float& _timer);
};
