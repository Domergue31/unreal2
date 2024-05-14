// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordCamera.h"
#include "RecordCameraManagerSubsystem.h"
#include "StreamingSourceManagerSubsystem.h"

ARecordCamera::ARecordCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	captureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>("CaptureComponent");
	RootComponent = captureComponent;
}

void ARecordCamera::SetDestination(const FVector _destination)
{
	destination = _destination;
	if (!isLerp)
	{
		SetActorLocation(destination);
		canMove = false;
		return;
	}
	canMove = !IsAtDestination();
}

void ARecordCamera::BeginPlay()
{
	Super::BeginPlay();
	URecordCameraManagerSubsystem* _recordManager = GetWorld()->GetGameInstance()->GetSubsystem<URecordCameraManagerSubsystem>();
	_recordManager->Register(name, this);
}

void ARecordCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void ARecordCamera::Move()
{
	canMove = !IsAtDestination();
	if (!canMove) return;
	SetActorLocation(FMath::Lerp(GetActorLocation(), destination, GetWorld()->DeltaRealTimeSeconds * speed));
}
