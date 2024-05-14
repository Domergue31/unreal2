// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterAnim.h"
#include "MainCharacter.h"

void UMainCharacterAnim::NativeBeginPlay()
{
	AMainCharacter* _player = Cast<AMainCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (!_player)
		return;
	_player->OnMove().AddDynamic(this, &UMainCharacterAnim::SetSpeed);
}

void UMainCharacterAnim::SetSpeed(float _speed)
{
	speed = _speed;
}
