// Fill out your copyright notice in the Description page of Project Settings.


#include "RevisionGameInstance.h"
#include "MainHUD.h"

void URevisionGameInstance::SwitchUI()
{
	AMainHUD* _hud = GetWorld()->GetFirstPlayerController()->GetHUD<AMainHUD>();
	if (_hud)
		_hud->SwitchUI();
}
