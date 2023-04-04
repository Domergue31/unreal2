// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectible.h"
#include "CoinCollectible.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API ACoinCollectible : public ACollectible
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		float rotateSpeed = 2;
private:
	void RotateCoin();
	void Save(AMarioCharacter* _mario);
protected:
	virtual void Tick(float _delta) override;
	virtual void CollectibleBehaviour(AMarioCharacter* _mario) override;
};
