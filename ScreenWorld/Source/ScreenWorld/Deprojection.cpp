// Fill out your copyright notice in the Description page of Project Settings.


#include "Deprojection.h"

ADeprojection::ADeprojection()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void ADeprojection::BeginPlay()
{
	Super::BeginPlay();
	MoveTargetAtViewportLocation();
}

void ADeprojection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MoveTargetWithMouse();
}

void ADeprojection::MoveTargetWithMouse()
{
	if (!target)
		return;
	FVector _worldLocation, _worldDirection;
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(_worldLocation, _worldDirection);
	target->SetActorLocation(_worldLocation + _worldDirection * depth);
}

void ADeprojection::MoveTargetAtViewportLocation()
{
	if (!target)
		return;
	int _x, _y;
	GetWorld()->GetFirstPlayerController()->GetViewportSize(_x, _y);
	FVector _worldLocation, _worldDirection;
	float _xPart = screenLocation.X * (float)_x,
		_yPart = screenLocation.Y * (float)_y;
	GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(_xPart, _yPart, _worldLocation, _worldDirection);
	target->SetActorLocation(_worldLocation + _worldDirection * depth);
}

