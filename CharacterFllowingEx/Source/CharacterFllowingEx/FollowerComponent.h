// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTERFLLOWINGEX_API UFollowerComponent : public UActorComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		float distance = 150.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		float speed = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		bool follow = true;
	
	FVector offset;

public:	
	UFollowerComponent();
	FORCEINLINE void SetTarget(TObjectPtr<AActor> _target) { target = _target; }
	FORCEINLINE void SetFollowEnable() { follow = true; }
	FORCEINLINE void SetFollowDisable() { follow = false; }
	FORCEINLINE FVector GetTargetLocation() const { return target ? target->GetActorLocation() : FVector(0); }
	FORCEINLINE FVector GetActorLocation() const { return GetOwner()->GetActorLocation(); }
	FORCEINLINE void SetOffset(FVector _offset) { offset = _offset; }
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void FollowTarget();
	void LookAtTarget();

};
