// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SightSystemComponent.h"
#include "AlienSightSystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class BTEXO_API UAlienSightSystemComponent : public USightSystemComponent
{
	GENERATED_BODY()
	



protected:
	virtual void UpdateSight() override;

};
