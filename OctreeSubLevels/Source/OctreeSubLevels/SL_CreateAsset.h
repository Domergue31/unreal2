// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SL_CreateAsset.generated.h"

/**
 * 
 */
UCLASS()
class OCTREESUBLEVELS_API USL_CreateAsset : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	static UObject* CreateAsset(const FString& _assetPath, UClass* _assetClass, UFactory* _assetFactory, bool& _bOutResult, FString& _outInfoMessage);
	
	UFUNCTION(BlueprintCallable)
	static UWorld* CreateWorldAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);

	UFUNCTION(BlueprintCallable)
	static UMaterial* CreateMaterialAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);

	UFUNCTION(BlueprintCallable)
	static UNiagaraSystem* CreateNiagaraSystemAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);

	UFUNCTION(BlueprintCallable)
	static ULevelSequence* CreateLevelSequenceAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);

	UFUNCTION(BlueprintCallable)
	static USoundCue* CreateSoundCueAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);


	UFUNCTION(BlueprintCallable)
	static UUserDefinedEnum* CreateEnumAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);

	UFUNCTION(BlueprintCallable)
	static UUserDefinedStruct* CreateStructAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage);

};
