// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainUI.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class REVISIONPROJECT_API AMainHUD : public AHUD
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TSubclassOf<UMainUI> mainUIRef = nullptr;
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UMainUI> mainUI = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<URevisionGameInstance> gi = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	void SwitchUI();
	
};
