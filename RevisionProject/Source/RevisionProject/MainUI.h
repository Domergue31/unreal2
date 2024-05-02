// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomWidget.h"
#include "RevisionGameInstance.h"
#include "MainUI.generated.h"

USTRUCT()
struct FCustomWidgetData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TSubclassOf<UCustomWidget> ref = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCustomWidget> widget = nullptr;

	FORCEINLINE TSubclassOf<UCustomWidget> GetRef() const { return ref;}
	FORCEINLINE TObjectPtr<UCustomWidget> GetWidget() { return widget; }
};

UCLASS(Blueprintable)
class REVISIONPROJECT_API UMainUI : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Widgets")
		TMap<EGameState, FCustomWidgetData> widgets;

public:
	void InitUI();
	void SwitchUI(URevisionGameInstance* _gi);

};
