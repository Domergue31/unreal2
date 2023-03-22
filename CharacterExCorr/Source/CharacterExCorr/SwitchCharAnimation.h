// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SwitchCharAnimation.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTEREXCORR_API USwitchCharAnimation : public UAnimInstance
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float forwardSpeed = 0;

	virtual void NativeBeginPlay() override;
	void Bind();
	UFUNCTION() void SetForwardSpeed(float _speed);
};
