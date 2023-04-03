// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SwitchData.h"
#include "TriggerLevels.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API ATriggerLevels : public ATriggerBox
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<USwitchData>  levelLoadData = nullptr;

	virtual void NotifyActorBeginOverlap(AActor* _other);
};
