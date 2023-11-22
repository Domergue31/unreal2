// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainPlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class CHARAINPUTPROJECTS_API UMainPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float forwardSpeed = 0;	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float rightSpeed = 0;


	virtual void NativeBeginPlay() override;

	UFUNCTION() void SetForwardSpeed(float _speed);
	UFUNCTION() void SetRightSpeed(float _speed);
};
