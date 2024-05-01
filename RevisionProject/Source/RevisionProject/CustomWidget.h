// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomWidget.generated.h"


#define ADDCLICKBUTTON(button, classe) button->OnClicked.AddDynamic(this, &classe::CallClickEvents);
UCLASS()
class REVISIONPROJECT_API UCustomWidget : public UUserWidget
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClickCustom);

	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnButtonClickCustom onButtonClickCustom;

public:
	FORCEINLINE FOnButtonClickCustom& OnButtonClickCustom() { return onButtonClickCustom; }



protected:
	virtual void NativeConstruct() override;

public:

	virtual void Show();
	virtual void Hide();

	virtual void InitEvents();

	UFUNCTION() void CallClickEvents();
};
