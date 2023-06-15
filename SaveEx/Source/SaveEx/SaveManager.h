// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameProgress.h"
#include "saveActor.h"
#include "SaveManager.generated.h"

/**
 * 
 */
UCLASS()
class SAVEEX_API USaveManager : public UObject
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere)
		TObjectPtr<UGameProgress> progress = nullptr;
public:
	void Init();
	void Save(AsaveActor* _actor);
	void Load(AsaveActor* _actor);
};
