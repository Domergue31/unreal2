// Fill out your copyright notice in the Description page of Project Settings.


#include "SorcererAnim.h"

void USorcererAnim::NativeBeginPlay()
{
	Bind();
}

void USorcererAnim::Bind()
{
	pawn = Cast<ASorcererCharacter>(TryGetPawnOwner());
	if (!pawn)
		return;
	pawn->OnMoveForward().AddDynamic(this, &USorcererAnim::SetForwardSpeed);
}

void USorcererAnim::SetForwardSpeed(float _speed)
{
	forwardSpeed = _speed;
}
