// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BrickLootBlock.generated.h"

UCLASS()
class MARIOPROJECT_API ABrickLootBlock : public ABlock
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		int maxTouch = 5;

	int currenttouch;
public:	
	ABrickLootBlock();
	virtual void Active() override;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
