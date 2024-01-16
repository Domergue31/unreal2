// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Path.h"
#include "PathManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GUARDAIPROJECT_API UPathManager : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere) TArray<APath*> paths = TArray<APath*>();

public:
	bool Register(APath* _path);
	bool UnRegister(APath* _path);

	APath* GetNearestPath(FVector _pos);
};
