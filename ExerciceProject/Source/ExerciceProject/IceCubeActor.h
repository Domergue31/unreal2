

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TimerComponent.h"
#include "IceCubeActor.generated.h"

UCLASS()
class EXERCICEPROJECT_API AIceCubeActor : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRespawnEnd);

	FOnRespawnEnd onRespawnEnd;



	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTimerComponent> customTimer = nullptr;

		bool respawn = false;
	UPROPERTY(EditAnywhere, Category = "Melt")
		bool canMelt = false;
	UPROPERTY(EditAnywhere, Category = Camera)
		bool isCameraOn = true;
	UPROPERTY(EditAnywhere, Category = "Debug")
		bool showDebug = true;
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool canMove = true;

	UPROPERTY(EditAnywhere, Category = "Movement|Speed")
		float respawnSpeed = 400.0f;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed")
		float speed = 500.0f;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed")
		float rotationSpeed = 100.0f;


	float fwdVelocity;
	float movementHeight;

	FVector initLocation, initScale;
	FRotator initRotation;

	
public:	
	AIceCubeActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void SetIceCube();
	void InitInput();

	void MoveForward(float _axis);
	void MoveRight(float _axis);
	void RotateYaw(float _axis);

	UFUNCTION() void Melt();
	void SetCanMeltEnable();
	UFUNCTION() void SetCanMeltDisable();
	UFUNCTION() void TimerFinish();

	void Respawn();
	void ResetIceCube();
	void SetRespawn();

	void ShowDebug();

};
