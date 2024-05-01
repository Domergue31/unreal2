// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"

void AMainHUD::BeginPlay()
{
	if (!mainUIRef) return;
	mainUI = NewObject<UMainUI>(this, mainUIRef);
	if (mainUI)
		//TODO Init MainUI;

	gi = GetWorld()->GetGameInstance<URevisionGameInstance>();
	if (gi)
		SwitchUI();
}

void AMainHUD::SwitchUI()
{

}
