// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerComponent.h"
#include "GridFollowerActor.generated.h"

UCLASS()
class ICECUBECORRECTION_API AGridFollowerActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> pawn = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTimerComponent> timer = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

		UPROPERTY(EditAnywhere)
		FVector targetLocation;
		FVector ancientLocation;
	UPROPERTY(EditAnywhere)
		float speed = 1;

public:	
	AGridFollowerActor();
	FORCEINLINE void SetTargetLocation(FVector _location) { targetLocation = _location; }
	FORCEINLINE FVector GetTargetLocation() { return targetLocation; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void MoveToTarget();
	void LookAtTarget();
	void IsMoving();
	UFUNCTION() void SetTargetLocation();
};
