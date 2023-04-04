// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MarioCharacter.h"
#include "MarioAnnim.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UMarioAnnim : public UAnimInstance
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<AMarioCharacter> pawn = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
		float moveSpeed = 0;
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
		float jumping = 0;
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
		float die = 0;

protected:
	virtual void NativeBeginPlay() override;
	void Bind();
	UFUNCTION() void SetMoveSpeed(float _speed);
	UFUNCTION() void SetDie(float _die);
	UFUNCTION() void SetJumping(float _jump);
};
