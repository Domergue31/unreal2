// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DetectionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BTEXO_API UDetectionComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetFound, AActor*, _target);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetDetected, bool, _detected);


	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnTargetFound onTargetFound;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnTargetDetected onTargetDetected;


	UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> layerToDetect;
	UPROPERTY(EditAnywhere) float detectionRange = 1000;
	UPROPERTY(VisibleAnywhere) TObjectPtr<AActor> target = nullptr;
	UPROPERTY(VisibleAnywhere) bool targetDetected = false;

public:	
	FORCEINLINE FOnTargetFound& OnTargetFound() { return onTargetFound;}
	FORCEINLINE FOnTargetDetected& OnTargetDetected() { return onTargetDetected;}
	FORCEINLINE TObjectPtr<AActor> GetTarget() { return target; }
	UDetectionComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Detect();
	void Debug();
};
