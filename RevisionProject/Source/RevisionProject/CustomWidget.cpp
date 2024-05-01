// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void UCustomWidget::NativeConstruct()
{
	Super::NativePreConstruct();
	bIsFocusable = true;
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(GetWorld()->GetFirstPlayerController());
}

void UCustomWidget::Show()
{
	if (!IsInViewport()) return;
	AddToViewport();
	APlayerController* _controller = GetWorld()->GetFirstPlayerController<APlayerController>();
	if (!_controller || _controller->bShowMouseCursor) return;
	_controller->SetShowMouseCursor(true);
}

void UCustomWidget::Hide()
{
	if (!IsInViewport()) return;
	RemoveFromViewport();
}

void UCustomWidget::InitEvents()
{
}

void UCustomWidget::CallClickEvents()
{
	onButtonClickCustom.Broadcast();
}
