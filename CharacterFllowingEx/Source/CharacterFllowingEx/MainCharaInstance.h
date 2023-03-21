// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacter.h"
#include "MainCharaInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERFLLOWINGEX_API UMainCharaInstance : public UAnimInstance
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<AMainCharacter> pawn = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float speed = 0.0f;

private:
	virtual void NativeBeginPlay() override;
	UFUNCTION() void SetSpeed(float _speed);
};
