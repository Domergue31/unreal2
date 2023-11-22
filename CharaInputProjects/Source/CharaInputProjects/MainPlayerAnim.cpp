// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerAnim.h"
#include "MainPlayer.h"

void UMainPlayerAnim::NativeBeginPlay()
{
	AMainPlayer* _player = Cast<AMainPlayer>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (!_player)
		return;
	_player->OnForwardMove().AddDynamic(this, &UMainPlayerAnim::SetForwardSpeed);
	_player->OnRightMove().AddDynamic(this, &UMainPlayerAnim::SetRightSpeed);
}

void UMainPlayerAnim::SetForwardSpeed(float _speed)
{
	forwardSpeed = _speed;
}

void UMainPlayerAnim::SetRightSpeed(float _speed)
{
	rightSpeed = _speed;
}
