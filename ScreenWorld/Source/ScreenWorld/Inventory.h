// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CollectibleItem.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class SCREENWORLD_API UInventory : public UObject
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	TMap<FString, ACollectibleItem*> inventory;


public:
	void Add(ACollectibleItem* _item);
	void Remove(ACollectibleItem* _item);

	FORCEINLINE TMap<FString, ACollectibleItem*> GetInventory() const { return inventory; }
	
};
