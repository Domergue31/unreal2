// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUICpp.h"

void UGameUICpp::NativeConstruct()
{
	Super::NativeConstruct();
	Bind();
}

void UGameUICpp::Bind()
{
	if (!playButton)
		return;
	playButton->OnClicked.AddDynamic(this, &UGameUICpp::Test);
}

void UGameUICpp::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("OK"));
}
