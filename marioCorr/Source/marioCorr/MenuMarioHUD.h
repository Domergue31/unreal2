// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MarioMenuUI.h"
#include "MenuMarioHUD.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API AMenuMarioHUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TSubclassOf<UMarioMenuUI> ui = nullptr;

	virtual void BeginPlay() override;
	void InitUi();


};
