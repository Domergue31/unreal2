// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainPlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class RICOCHETARROW_API UMainPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float speed = 0;

public:
	void virtual NativeBeginPlay() override;

	UFUNCTION() void SetSpeed(float _speed);
};
