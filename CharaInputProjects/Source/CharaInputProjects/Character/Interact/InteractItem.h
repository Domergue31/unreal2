// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InteractItem.generated.h"

/**
 * 
 */
UCLASS()
class CHARAINPUTPROJECTS_API AInteractItem : public AStaticMeshActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Interact")
	FLinearColor interactColor = FLinearColor::Green;
	UPROPERTY(EditAnywhere, Category="Interact")
	FLinearColor defaultColor = FLinearColor::Green;

	UPROPERTY() TObjectPtr<UMaterialInstanceDynamic> 
	dynamicMaterialColor = nullptr;


	virtual void BeginPlay() override;

public:
	void ApplyInteractColor();
	void ResetDefaultColor();
};
