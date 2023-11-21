// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerAnim.h"
#include "MainPlayer.h"

void UMainPlayerAnim::NativeBeginPlay()
{
	AMainPlayer* _chara = Cast<AMainPlayer>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (!_chara)
		return;
	_chara->OnMove().AddDynamic(this, &UMainPlayerAnim::SetSpeed);
}

void UMainPlayerAnim::SetSpeed(float _speed)
{
	speed = _speed;
}
