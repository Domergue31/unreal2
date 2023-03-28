// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "BrickBlock.generated.h"

UCLASS()
class MARIOPROJECT_API ABrickBlock : public ABlock
{
	GENERATED_BODY()
	
public:	
	ABrickBlock();
	virtual void Active() override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
