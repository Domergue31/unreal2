// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnModule.h"
#include "LineSpawnModule.generated.h"

/**
 * 
 */
UCLASS()
class TOOLPROJECT_API ULineSpawnModule : public USpawnModule
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Line Spawn", meta = (UIMin = 1, UIMax = 100, ClampMin = 1, ClampMax = 100)) int itemNumber = 10;
	UPROPERTY(EditAnywhere, Category = "Line Spawn", meta = (UIMin = 100, UIMax = 1000, ClampMin = 100, ClampMax = 1000)) int gap = 10;


public:
	virtual void DrawDebug(UWorld* _world, const FVector& _origin) override;
	virtual TArray<AActor*> Spawn(class ASpawnTool* _tool) override;
};
