// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Block.h"
#include "BlockTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API ABlockTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<ABlock> block;

public:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* _other);
	virtual void NotifyActorEndOverlap(AActor* _other);
	UFUNCTION() void Break();
};
