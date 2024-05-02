// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUI.h"

void UMainUI::InitUI()
{
	for each (TTuple<EGameState, FCustomWidgetData> _data in widgets)
	{
		if (_data.Value.GetRef())
			URevisionGameInstance::InitCustomWidget<UCustomWidget>(_data.Value.GetRef(), *_data.Value.GetWidget());
	}
}

void UMainUI::SwitchUI(URevisionGameInstance* _gi)
{
	EGameState _state = _gi->GetGameState();
	if (!widgets.Contains(_state)) return;
	for (int i = 0; i < widgets.Num(); i++)
	{ 
		if (widgets.Contains((EGameState)i))
			widgets[(EGameState)i].GetWidget()->Hide();
	}
	widgets.Find(_state)->GetWidget()->Show();
	TEnumAsByte<EGameState> test;
	test.
}