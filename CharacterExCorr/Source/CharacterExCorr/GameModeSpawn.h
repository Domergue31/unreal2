// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DataObject.h"
#include "GameModeSpawn.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTEREXCORR_API AGameModeSpawn : public AGameModeBase
{
	GENERATED_BODY()
	
		//TSoftObjectptr<AItem> reflevel = nullptr;
		//TSubclassOf<AItem> refCopy = nullptr;

		//FORCEINLINE GetItem()
		//{
		//		if (refLevel.Isvalid())
		//		{
		//				refLevel.Get();
		//		}
		//		else
		//		{
		//				refLevel = GetWorld()->SpawnActor(refToCopy);
		//				return refLevel;
		//		}
		//}

	
	
		UPROPERTY()
		TObjectPtr<UDataObject> data = nullptr;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> timerManagerRef = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> timerManager = nullptr;
public:
	FORCEINLINE TObjectPtr<UDataObject> GetData() const { return data; }
	FORCEINLINE TObjectPtr<AActor> GetTimerManager() const { return timerManager; }
private:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
};
