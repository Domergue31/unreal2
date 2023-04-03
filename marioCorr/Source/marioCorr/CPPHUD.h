// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameUICpp.h"
#include "CPPHUD.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API ACPPHUD : public AHUD
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSubclassOf<UGameUICpp> ui = nullptr;
		virtual void BeginPlay() override;
		void InitHUD();
};
