// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "TalosDoor.generated.h"

/**
 * 
 */
UCLASS()
class EXAMP2CORRECTION_API ATalosDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	void OpenDoor();
	void CloseDoor();
};
