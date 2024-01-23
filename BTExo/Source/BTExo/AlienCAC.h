// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Alien.h"
#include "AlienCAC.generated.h"

/**
 * 
 */
UCLASS()
class BTEXO_API AAlienCAC : public AAlien
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TObjectPtr<UBehaviorTree> attackTree = nullptr;
	UPROPERTY(EditAnywhere) FName alienBTKey_TargetActor = "";

protected: 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	virtual void Detect() override;

};
