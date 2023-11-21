#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "RicochetLauncherSettings.h"
#include "MainPlayer.generated.h"

UCLASS()
class RICOCHETARROW_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMove, float, _axis);

	UPROPERTY(BlueprintCallable, BlueprintReadWrite, meta = (AllowPrivateAccess))
	FOnMove onMove;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere, Category="Movement", meta = (UIMin = 0, ClampMin = 0))
	float movementSpeed = 2;

	UPROPERTY(EditAnywhere, Category="shoot")
	TObjectPtr<URicochetLauncherSettings> ricochetSettings = nullptr;
public:
	AMainPlayer();
	FORCEINLINE FOnMove& OnMove() { return onMove; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void MoveForward(float _axis);
	void MoveRight(float _axis);
	void MoveCameraVertical(float _axis);
	void MoveCameraHorizontal(float _axis);

	void ShootArrow();
	TArray<FVector> CalculateTraj();
};
