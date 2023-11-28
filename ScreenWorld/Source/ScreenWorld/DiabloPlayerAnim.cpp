// Fill out your copyright notice in the Description page of Project Settings.


#include "DiabloPlayerAnim.h"
#include "DiabloPlayer.h"

void UDiabloPlayerAnim::NativeBeginPlay()
{
	ADiabloPlayer* _player = Cast<ADiabloPlayer>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (!_player)
		return;
	_player->Navigation()->OnMove().AddDynamic(this, &UDiabloPlayerAnim::SetSpeed);
}

void UDiabloPlayerAnim::SetSpeed(float _speed)
{
	speed = _speed;
}
