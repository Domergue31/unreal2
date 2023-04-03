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
}

void UMarioAnnim::SetMoveSpeed(float _speed)
{
	moveSpeed = _speed;
	UE_LOG(LogTemp, Warning, TEXT("%f"), moveSpeed);

}
