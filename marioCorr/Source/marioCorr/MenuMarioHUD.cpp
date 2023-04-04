// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuMarioHUD.h"

void AMenuMarioHUD::BeginPlay()
{
	Super::BeginPlay();
	InitUi();
}

void AMenuMarioHUD::InitUi()
{
	UMarioMenuUI* _ui = CreateWidget<UMarioMenuUI>(GetWorld(), ui);
	if (!_ui)
		return;
	_ui->AddToViewport();
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}
