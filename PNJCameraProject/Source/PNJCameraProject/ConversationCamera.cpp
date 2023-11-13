// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationCamera.h"
#include "PNJActor.h"


AConversationCamera::AConversationCamera()
{
	PrimaryActorTick.bCanEverTick = true;

}

FVector AConversationCamera::FinalPosition(APNJActor* _pnj)
{
	FVector _center = _pnj->GetActorLocation() + _pnj->GetActorForwardVector() * (_pnj->Settings()->Distance() / 2);
	FVector _trigo = GetTrigoPosition(_pnj->Settings()->Distance() / 1.5f, _pnj->Settings()->Angle());
	return _center + _trigo + FVector(0, 0, _pnj->Settings()->CameraHeight());
}