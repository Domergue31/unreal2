// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputMappingContext.h"
#include "InputConfig.generated.h"

/**
 * 
 */
UCLASS()
class CHARAINPUTPROJECTS_API UInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TSoftObjectPtr<UInputMappingContext> context = nullptr;

	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> forward = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> interact = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> rotate = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> jump = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example Input")
	TObjectPtr<UInputAction> lookAt = nullptr;



public:
	FORCEINLINE TSoftObjectPtr<UInputMappingContext> ContextInput() const { return context; }
	FORCEINLINE TObjectPtr<UInputAction> ForwardInput() const { return forward; }
	FORCEINLINE TObjectPtr<UInputAction> InteractInput() const { return interact; }
	FORCEINLINE TObjectPtr<UInputAction> RotateInput() const { return rotate; }
	FORCEINLINE TObjectPtr<UInputAction> JumpInput() const { return jump; }
	FORCEINLINE TObjectPtr<UInputAction> LookAtInput() const { return lookAt; }

	void EnableInputContext(ULocalPlayer* _player);
};
