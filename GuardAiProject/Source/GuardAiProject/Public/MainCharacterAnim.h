// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacterAnim.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UMainCharacterAnim : public UAnimInstance
{
	GENERATED_BODY()


	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess)) float speed = 0;



protected:
	virtual void NativeBeginPlay() override;

	UFUNCTION() void SetSpeed(float _speed);
	
};
