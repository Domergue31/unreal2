// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include <Components/TextBlock.h>
#include "GameUICpp.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UGameUICpp : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UImage> coinImage = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UTextBlock> coins = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UTextBlock> score = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UTextBlock> mario = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UTextBlock> Time = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UTextBlock> timer = nullptr;

	virtual void NativeConstruct() override;
	UFUNCTION() void SetScoreText(int _value);
	UFUNCTION() void SetCoinText(int _value);
	UFUNCTION() void SetTimerText(int _value);
private:
	void Init(class UMarioGameInstance* _gi);

};
