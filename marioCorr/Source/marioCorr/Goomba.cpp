// Fill out your copyright notice in the Description page of Project Settings.


#include "Goomba.h"

void AGoomba::GlobalBehaviour(AMarioCharacter* _mario)
{
	if (isDead)
		return;
	_mario->Die();
}

void AGoomba::UpBehaviour(AMarioCharacter* _mario)
{
	if (_mario && _mario->IsDead() || _mario->GetStartShrinkEffect())
		return;
	Die();
}

void AGoomba::Die()
{
	AEnnemy::Die();
	if (isDead)
		return;
	SetActorScale3D(GetActorScale() * FVector(1.3f, 1.3f, .2f));
	SetLifeSpan(2);
	isDead = true;
}

