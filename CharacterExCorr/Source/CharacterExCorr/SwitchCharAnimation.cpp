// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchCharAnimation.h"
#include "MainCharacter.h"

void USwitchCharAnimation::NativeBeginPlay()
{
	Bind();
}

void USwitchCharAnimation::Bind()
{
	AMainCharacter* _cast = Cast<AMainCharacter>(TryGetPawnOwner());
	if (!_cast)
		return;
	_cast->OnMoveForward().AddDynamic(this, &USwitchCharAnimation::SetForwardSpeed);
}

void USwitchCharAnimation::SetForwardSpeed(float _speed)
{
	forwardSpeed = _speed;
}
