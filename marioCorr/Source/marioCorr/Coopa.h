// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ennemy.h"
#include "MarioCharacter.h"
#include "Coopa.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API ACoopa : public AEnnemy
{
	GENERATED_BODY()
	
private:
	void Save();
protected:
	virtual void GlobalBehaviour(AMarioCharacter* _mario) override;
	virtual void UpBehaviour(AMarioCharacter* _mario) override;
	virtual void Die() override;
};
