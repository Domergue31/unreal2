// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SaveManager.h"
#include "SaveGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SAVEEX_API USaveGameInstance : public UGameInstance
{
	GENERATED_BODY()
		UPROPERTY()
		TObjectPtr<USaveManager> saveManager = nullptr;

public:
	FORCEINLINE TObjectPtr<USaveManager> GetSaveManager() const { return saveManager; }
		virtual void Init() override;
};
