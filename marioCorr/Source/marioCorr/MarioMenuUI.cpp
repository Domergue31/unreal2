// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioMenuUI.h"

void UMarioMenuUI::NativeConstruct()
{
	Super::NativeConstruct();
	Bind();
}

void UMarioMenuUI::Bind()
{
	if (playButton)
	{
		playButton->OnClicked.AddDynamic(this, &UMarioMenuUI::Play);
	}
	if (exitButton)
	{
		exitButton->OnClicked.AddDynamic(this, &UMarioMenuUI::Exit);
	}
}

void UMarioMenuUI::Play()
{
	if (!levelLoadData)
		return;
	levelLoadData->LoadLevel(GetWorld());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
}

void UMarioMenuUI::Exit()
{
	exit(1);
}
