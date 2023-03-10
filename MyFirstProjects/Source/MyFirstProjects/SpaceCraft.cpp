// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraft.h"
#include "InputUtils.h"
#include "Utils.h"

ASpaceCraft::ASpaceCraft()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Game/Meshes/SpaceShip/source.source'")));
	mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Game/Meshes/SpaceShip/Material__31_026_Inst.Material__31_026_Inst'")));
}

void ASpaceCraft::BeginPlay()
{
	Super::BeginPlay();
	initLocation = GetActorLocation();
	initRotation = GetActorRotation();
	SetUpInput();
}

void ASpaceCraft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ShowDebug();
	
}


void ASpaceCraft::SetUpInput()
{
	BIND_AXIS(VERTICAL, this, &ASpaceCraft::MoveForward)
	BIND_AXIS(HORIZONTAL, this, &ASpaceCraft::MoveToward)
	BIND_AXIS(PITCHROTATION, this, &ASpaceCraft::PitchRotation)
	BIND_AXIS(ROLLROTATION, this, &ASpaceCraft::RollRotation)
}



void ASpaceCraft::MoveForward(float _axis)
{
	FVector _result = GetActorRightVector().GetSafeNormal();
	SetActorLocation(GetActorLocation() + (_result * _axis * DELTATIME * forwardSpeed));
}

void ASpaceCraft::MoveToward(float _axis)
{
	FVector _result = GetActorForwardVector().GetSafeNormal();
	SetActorLocation(GetActorLocation() + (_result * (_axis * -1) * DELTATIME * towardSpeed));
}

void ASpaceCraft::PitchRotation(float _axis)
{
	SetActorRotation(GetActorRotation() + FRotator(0, 0, (_axis * -1) * rotationSpeed * DELTATIME));
}

void ASpaceCraft::RollRotation(float _axis)
{
	SetActorRotation(GetActorRotation() + FRotator(0, _axis * rotationSpeed * DELTATIME, 0));
}


//void ASpaceCraft::Rotation_Interp(FRotator _from, FRotator _to)
//{
//	float _test = _from.Pitch;
//	float _test2 = _to.Pitch;
//	const FVector _result = FMath::VInterpConstantTo(_from.Pitch, , DELTATIME, rotationSpeed);
//	const FVector _result = FMath::Lerp(_test, _test2, DELTATIME * rotationSpeed);
//
//	FRotator _newRotation = FRotator(_result.X, _result.Y, _result.Z);
//	SetActorRotation(_newRotation);
//}

void ASpaceCraft::ShowDebug()
{
	for (TObjectPtr<AActor> _planet : planets)
	{
		float _distance = FVector::Distance(GetActorLocation(), _planet->GetActorLocation());
		LOG_W(LogTemp, "%f", _distance)
		DRAW_SPHERE(_planet->GetActorLocation(), 55 * GetActorScale().X, FColor::Yellow, 2)
		DRAW_LINE(GetActorLocation(), _planet->GetActorLocation(), FColor::Red, 2)
	}
}
