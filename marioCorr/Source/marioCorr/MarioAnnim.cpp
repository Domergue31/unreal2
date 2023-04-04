// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioAnnim.h"

void UMarioAnnim::NativeBeginPlay()
{
	Bind();
}

void UMarioAnnim::Bind()
{
	pawn = Cast<AMarioCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!pawn)
		return;
	pawn->OnMove().AddDynamic(this, &UMarioAnnim::SetMoveSpeed);
	pawn->OnJump().AddDynamic(this, &UMarioAnnim::SetJumping);
	pawn->OnDie().AddDynamic(this, &UMarioAnnim::SetDie);
}

void UMarioAnnim::SetMoveSpeed(float _speed)
{
	moveSpeed = _speed;
}

void UMarioAnnim::SetDie(float _die)
{
	die = _die;
	UE_LOG(LogTemp, Warning, TEXT("%f"), die);
}

void UMarioAnnim::SetJumping(float _jump)
{
	jumping = _jump;
}
