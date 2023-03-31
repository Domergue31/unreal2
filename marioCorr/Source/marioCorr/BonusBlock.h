// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "Collectible.h"
#include "BonusBlock.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API ABonusBlock : public ABlock
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSubclassOf<ACollectible> bonusElement = nullptr;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> bonusBlockGraphics = nullptr;
	UPROPERTY(EditAnywhere)
		FVector offsetSpawnBonus = FVector(0, 0, 150);
protected:
	virtual void DownBehaviour(AMarioCharacter* _char) override;
};
