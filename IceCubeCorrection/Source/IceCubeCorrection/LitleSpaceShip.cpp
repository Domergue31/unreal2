// Fill out your copyright notice in the Description page of Project Settings.


#include "LitleSpaceShip.h"
#include "Utils.h"
#include "InputUtils.h"

ALitleSpaceShip::ALitleSpaceShip()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Game/Meshes/source.source'")));
	mesh->SetMaterial(0, LoadObject<UMaterial>(this, TEXT("'/Game/Meshes/Material__31_026_Inst.Material__31_026_Inst'")));
}

void ALitleSpaceShip::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(.4f));
}

// Called every frame
void ALitleSpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ShowDebug();
	InitPosition();
	FollowThePawn();
}


void ALitleSpaceShip::InitPosition()
{
	if (position.position1 == true)
	{
		FVector _result = PAWN->GetActorForwardVector().GetSafeNormal();
		position.targetPosition = PAWN->GetActorLocation() + _result * 100;
	}
	else if (position.position2 == true)
	{
		FVector _result = PAWN->GetActorForwardVector().GetSafeNormal();
		position.targetPosition = PAWN->GetActorLocation() + _result * -150;
	}
	else if (position.position3 == true)
	{
		FVector _result = PAWN->GetActorRightVector().GetSafeNormal();
		position.targetPosition = PAWN->GetActorLocation() + _result * 120;
	}
	else if (position.position4 == true)
	{
		FVector _result = PAWN->GetActorRightVector().GetSafeNormal();
		position.targetPosition = PAWN->GetActorLocation() + _result * -120;
	}
}

void ALitleSpaceShip::ShowDebug()
{
	DRAW_BOX(position.targetPosition, FVector(2), FColor::Red, 2);
	DRAW_LINE(position.targetPosition, GetActorLocation(), FColor::Red, 2);
}

void ALitleSpaceShip::FollowThePawn()
{
	FVector _result = LERP(GetActorLocation(), position.targetPosition, DELTATIME);
	SetActorLocation(_result);
}
