// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "DestructibleBlock.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API ADestructibleBlock : public ABlock
{
	GENERATED_BODY()
private:
	void Save(class AMarioCharacter* _mario);
protected:	
	virtual void DownBehaviour(class AMarioCharacter* _char) override;
};
