// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "Elements.h"
#include "LootBlock.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API ALootBlock : public ABlock
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TSubclassOf<AElements> element = nullptr;
	UPROPERTY(editAnywhere)
		bool used = false;
public:
	ALootBlock();
	virtual void Active() override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Used();
};
