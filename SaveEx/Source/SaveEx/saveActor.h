// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "saveActor.generated.h"

/**
 * 
 */
UCLASS()
class SAVEEX_API AsaveActor : public AStaticMeshActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, Category = Player)
		int playerLife = 100;

public:
	FORCEINLINE void SetLife(const int& _life) { playerLife = _life; }
	FORCEINLINE int GetLife() const { return playerLife; }
protected:
	virtual void BeginPlay() override;
	void InitDatas();
	void AutoSavePlayerExample();
};
