// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PathhManager.generated.h"

/**
 * 
 */
UCLASS()
class PATHCORR_API UPathhManager : public UObject
{
	GENERATED_BODY()
	UPROPERTY()
		TArray<class APathActor*> allPaths;
public:
	void AddPath(class APathActor* _path);
	class APathActor* GetPath() const ;
};
