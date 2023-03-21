// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharaInstance.h"

void UMainCharaInstance::NativeBeginPlay()
{
	pawn = Cast<AMainCharacter>(TryGetPawnOwner());
	if (!pawn)
		return;
	pawn->OnMoveForward().AddDynamic(this, &UMainCharaInstance::SetSpeed);
}

void UMainCharaInstance::SetSpeed(float _speed)
{
	speed = _speed;
}
