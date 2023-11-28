// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DiabloPlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class SCREENWORLD_API UDiabloPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
	

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess))
		float speed = 0;


	virtual void NativeBeginPlay() override;

public:
	UFUNCTION() void SetSpeed(float _speed);
};
