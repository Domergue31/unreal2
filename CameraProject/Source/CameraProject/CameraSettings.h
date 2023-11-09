// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraSettings.generated.h"


UENUM()
enum EOffsetType
{
	World,
	Local
};

UENUM()
enum EMovementType
{
	Lerp,
	ConstantLerp
};

UCLASS()
class CAMERAPROJECT_API UCameraSettings : public UDataAsset
{
	GENERATED_BODY()
	


};
