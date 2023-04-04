// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "SwitchData.h"
#include "MarioMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UMarioMenuUI : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UButton> playButton = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess, BindWidget))
		TObjectPtr<UButton> exitButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintreadWrite, meta = (AllowPrivateAccess))
		TObjectPtr<USwitchData>  levelLoadData = nullptr;


	virtual void NativeConstruct() override;

	void Bind();
	UFUNCTION() void Play();
	UFUNCTION() void Exit();
};
