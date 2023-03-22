// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SorcererCharacter.h"
#include "SorcererAnim.generated.h"

/**
 * 
 */
UCLASS()
class FIREBALLPROJECT_API USorcererAnim : public UAnimInstance
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<ASorcererCharacter> pawn = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float forwardSpeed = 0.0f;

private:
	virtual void NativeBeginPlay() override;
	void Bind();
	UFUNCTION() void SetForwardSpeed(float _speed);
};
