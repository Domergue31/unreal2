// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "PawnInputExample.generated.h"

UCLASS()
class CCC_2023_API APawnInputExample : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Example Input")
		TSoftObjectPtr<UInputMappingContext> inputContext = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
		TObjectPtr<UInputAction> movementInputs = nullptr;
public:
	APawnInputExample();

protected:
	void InitInputSystem();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForwardTest(const FInputActionValue& _value);
};
