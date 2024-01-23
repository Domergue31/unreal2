// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SightSystemComponent.generated.h"


UCLASS( Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BTEXO_API USightSystemComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> layerMask;
	UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMin = 0, UMax = 360, ClampMax = 360)) int sightAngle = 90;
	UPROPERTY(EditAnywhere, meta = (UMin = 100, ClampMin = 100)) int range = 500;
	UPROPERTY(EditAnywhere) int definition = 10;
	UPROPERTY(EditAnywhere) float sightHeight = 0;

	TObjectPtr<AActor> targetSight = nullptr;
public:	
	FORCEINLINE FVector GetSightHeightLocation() const { return GetOwner()->GetActorLocation() + FVector(0, 0, sightHeight); }
	FORCEINLINE AActor* GetTargetSight() { return targetSight; }
	USightSystemComponent();

	FORCEINLINE void ClearTarget() { targetSight = nullptr; }


protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void UpdateSight();
};
