 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SL_CreateBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class OCTREESUBLEVELS_API USL_CreateBlueprint : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	


public:
	/**
	* Editor Only
	* 
	* Create a blueprint asset
	* 
	* @param BlueprintPath => path of the blueprint
	* @param bOutSucces => if the action was a succes or not 
	* @param OutInfioMessage => more informations about the result 
	* 
	* @return the created blueprint
	*/
	UFUNCTION(BlueprintCallable, Category = "Custom|Create Blueprint")
	static UBlueprint* CreateBlueprint(const FString& _blueprintPath, TSubclassOf<UObject> _parentClass, bool& _bOutSuccess, FString& _outInfoMessage);
};
