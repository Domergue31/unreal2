
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "MainPlayer.generated.h"

UCLASS()
class CHARAINPUTPROJECTS_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnForwardMove, float, _axis);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRightMove, float, _axis);

	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccesse))
	FOnForwardMove onForwardMove;
	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccesse))
	FOnRightMove onRightMove;

#pragma region f/p
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere, Category="Example Input")
	TSoftObjectPtr<UInputMappingContext> inputContext = nullptr;
	UPROPERTY(EditAnywhere, Category="Example Input")
	TObjectPtr<UInputAction> forwardInput = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> rightInput = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> cameraYawInput = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> cameraPitchInput = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> takePLaceObjectInput = nullptr;

	UPROPERTY(EditAnywhere, Category="Speed", meta = (UIMin = 0.1, ClampMin = 0.1))
		float movementSpeed = 1;
	UPROPERTY(EditAnywhere, Category="Speed", meta = (UIMin = 0.1, ClampMin = 0.1))
		float cameraYawSpeed = 1;
	UPROPERTY(EditAnywhere, Category="Speed", meta = (UIMin = 0.1, ClampMin = 0.1))
		float cameraPitchSpeed = 1;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AActor> objectTaken = nullptr;
	UPROPERTY(EditAnywhere, Category="Line Trace")
	TArray<TEnumAsByte<EObjectTypeQuery>> placeObjectsType;
	UPROPERTY(EditAnywhere, Category="Line Trace")
	TArray<TEnumAsByte<EObjectTypeQuery>> takeObjetcType;

#pragma endregion
public:
	AMainPlayer();
	FORCEINLINE FOnForwardMove& OnForwardMove() { return onForwardMove; }
	FORCEINLINE FOnRightMove& OnRightMove() { return onRightMove; }
protected:
	void InitInput();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(const FInputActionValue& _value);
	void MoveRight(const FInputActionValue& _value);
	void RotateCameraYaw(const FInputActionValue& _value);
	void RotateCameraPitch(const FInputActionValue& _value);

	void InteractCollectibleObject(const FInputActionValue& _value);

	bool CanPlaceObject();
	AActor* IsObjectInFront();

};
