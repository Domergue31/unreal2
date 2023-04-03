// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectible.h"
#include "PowerUp.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API APowerUp : public ACollectible
{
	GENERATED_BODY()
	
protected:
	virtual void CollectibleBehaviour(AMarioCharacter* _mario) override;
};
