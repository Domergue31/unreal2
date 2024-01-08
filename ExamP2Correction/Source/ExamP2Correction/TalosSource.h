// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TalosNode.h"
#include "TalosSource.generated.h"

/**
 * 
 */
UCLASS()
class EXAMP2CORRECTION_API ATalosSource : public ATalosNode
{
	GENERATED_BODY()
	
public:
	virtual void NodeBehaviour() override;
};
