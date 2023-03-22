// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SecondCharacter.generated.h"

UCLASS()
class CHARACTEREXCORR_API ASecondCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASecondCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
