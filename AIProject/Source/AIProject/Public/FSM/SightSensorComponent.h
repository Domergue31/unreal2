// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SightSensorComponent.generated.h"


UCLASS( Abstract,ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIPROJECT_API USightSensorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMin = 0, UMax = 360, ClampMax = 360)) int sightAngle = 90;
	UPROPERTY(EditAnywhere) int range = 500;
	UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> layers = {};
public:
	UPROPERTY(EditAnywhere) int definition = 10;
	UPROPERTY(EditAnywhere) float sightHeight = 100;
	
	UPROPERTY(VisibleAnywhere) TObjectPtr<AActor> targetSight = nullptr;

public:	
	USightSensorComponent();
	FORCEINLINE AActor* TargetSight() { return targetSight; }
	FORCEINLINE FVector GetSightOffsetLocation() const { return GetOwnerLocation() + FVector(0, sightHeight, 0); }


	FORCEINLINE FVector GetOwnerLocation() const { return GetOwner()->GetActorLocation(); }
	FORCEINLINE void ClearSight() { targetSight = nullptr; }

protected:
	virtual void UpdateSight();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
