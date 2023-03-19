// Fill out your copyright notice in the Description page of Project Settings.


#include "GridFollowerActor.h"
#include "Utils.h"
#include "InputUtils.h"

// Sets default values
AGridFollowerActor::AGridFollowerActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	timer = CreateDefaultSubobject<UTimerComponent>("Timer");
	AddOwnedComponent(timer);
}

// Called when the game starts or when spawned
void AGridFollowerActor::BeginPlay()
{
	Super::BeginPlay();
	pawn = PAWN;
	ancientLocation = pawn->GetActorLocation();
	BIND(timer->OnTimerEnd(), this, &AGridFollowerActor::SetTargetLocation);
	timer->StartTimer();
}

// Called every frame
void AGridFollowerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	IsMoving();
	LookAtTarget();
	MoveToTarget();
}

void AGridFollowerActor::MoveToTarget()
{
	SetActorLocation(LERP(GetActorLocation(), targetLocation, DELTATIME * speed));
}

void AGridFollowerActor::LookAtTarget()
{
	FRotator _rot = GetActorRotation();
	FRotator _newRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), targetLocation);
	_rot.Yaw = _newRot.Yaw;
	SetActorRotation(_rot);
}

void AGridFollowerActor::IsMoving()
{
	if (!pawn)
		return;
	if (ancientLocation != pawn->GetActorLocation())
	{
		timer->ResetTimer();
		ancientLocation = pawn->GetActorLocation();
	}
}

void AGridFollowerActor::SetTargetLocation()
{
	targetLocation = pawn->GetActorLocation();
}

