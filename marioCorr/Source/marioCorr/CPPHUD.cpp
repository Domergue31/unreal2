// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHUD.h"

void ACPPHUD::BeginPlay()
{
	Super::BeginPlay();
	InitHUD();
}

void ACPPHUD::InitHUD()
{
	UGameUICpp* _ui = CreateWidget<UGameUICpp>(GetWorld(), ui);
	if (!_ui)
		return;
	_ui->AddToViewport();
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}
