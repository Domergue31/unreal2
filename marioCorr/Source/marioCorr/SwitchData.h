// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/Character.h"
#include <Kismet/GameplayStatics.h>
#include "SwitchData.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API USwitchData : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UWorld> level = nullptr;
public:
	FORCEINLINE void LoadLevel(UWorld* _world)
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(_world, level);
	}
};
