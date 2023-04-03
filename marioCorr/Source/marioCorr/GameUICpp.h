// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "GameUICpp.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UGameUICpp : public UUserWidget
{
	GENERATED_BODY()
		UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UButton> playButton = nullptr;

	virtual void NativeConstruct() override;

	void Bind();
	UFUNCTION() void Test();
};
