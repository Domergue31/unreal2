// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUICpp.h"
#include "MarioGameInstance.h"

void UGameUICpp::NativeConstruct()
{
	Super::NativeConstruct();
	UMarioGameInstance* _gi = GetWorld()->GetGameInstance< UMarioGameInstance>();
	if (!_gi)
		return;
	_gi->GetScore()->OnAddScore().AddDynamic(this, &UGameUICpp::SetScoreText);
	_gi->GetCoins()->OnAddCoin().AddDynamic(this, &UGameUICpp::SetCoinText);
	_gi->GetTimer()->OnTimerProgress().AddDynamic(this, &UGameUICpp::SetTimerText);
	Init(_gi);
}

void UGameUICpp::SetScoreText(int _value)
{
	if (!score)
		return;
	score->SetText(FText::AsNumber(_value));
}


void UGameUICpp::SetCoinText(int _value)
{
	if (!coins)
		return;
	coins->SetText(FText::AsNumber(_value));
}

void UGameUICpp::SetTimerText(int _value)
{
	if (!timer)
		return;
	timer->SetText(FText::AsNumber(_value));
}

void UGameUICpp::Init(UMarioGameInstance* _gi)
{
	coins->SetText(FText::AsNumber(_gi->GetCoins()->GetCoins()));
	score->SetText(FText::AsNumber(_gi->GetScore()->GetScore()));
	timer->SetText(FText::AsNumber(_gi->GetTimer()->GetTickProgress()));
}
