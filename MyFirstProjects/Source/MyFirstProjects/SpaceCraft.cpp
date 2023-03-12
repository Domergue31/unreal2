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
	onMove.AddDynamic(this, &ASpaceCraft::SetPlanetScale);
	InitPlanetsScale(GetActorLocation());
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
	BIND_ACTION(RESPAWN, EInputEvent::IE_Pressed, this, &ASpaceCraft::Respawn)
	BIND_ACTION(RESETROTATION, EInputEvent::IE_Pressed, this, &ASpaceCraft::ResetRotation)
}



void ASpaceCraft::MoveForward(float _axis)
{
	FVector _result = GetActorRightVector().GetSafeNormal();
	SetActorLocation(GetActorLocation() + (_result * _axis * DELTATIME * forwardSpeed));
	onMove.Broadcast();
}

void ASpaceCraft::MoveToward(float _axis)
{
	FRotator _actualRotation = GetActorRotation();
	if (_axis >= 1.0f)
	{
		TowardRotation_Interp(_actualRotation, FRotator(75, _actualRotation.Yaw, _actualRotation.Roll), towardRotationSpeed, _axis);
	}
	else if (_axis <= -1.0f)
	{
		TowardRotation_Interp(_actualRotation, FRotator(-75, _actualRotation.Yaw, _actualRotation.Roll), towardRotationSpeed, _axis);
	}
	else
	{
		TowardRotation_Interp(_actualRotation, FRotator(initRotation.Pitch, _actualRotation.Yaw, _actualRotation.Roll), towardRotationSpeed * 2, _axis);
	}
}

void ASpaceCraft::PitchRotation(float _axis)
{
	SetActorRotation(GetActorRotation() + FRotator(0, 0, (_axis * -1) * rotationSpeed * DELTATIME));
}

void ASpaceCraft::RollRotation(float _axis)
{
	SetActorRotation(GetActorRotation() + FRotator(0, _axis * rotationSpeed * DELTATIME, 0));
}

void ASpaceCraft::TowardRotation_Interp(FRotator _from, FRotator _to, float _speed, float _axis)
{
	if (_from.Pitch != _to.Pitch)
	{
		const float _newPitch = FMath::Lerp(_from.Pitch, _to.Pitch, DELTATIME * _speed);
		const FRotator _newRotation = FRotator(_newPitch, _from.Yaw, _from.Roll);
		SetActorRotation(_newRotation);
		RollRotation(_axis);
	}
}

void ASpaceCraft::Respawn()
{
	SetActorLocation(initLocation);
}

void ASpaceCraft::ResetRotation()
{
	FRotator _actualRotation = GetActorRotation();
	SetActorRotation(FRotator(initRotation.Pitch, _actualRotation.Yaw, initRotation.Roll));
}


void ASpaceCraft::ShowDebug()
{
	for (TObjectPtr<AActor> _planet : planets)
	{
		DRAW_SPHERE(_planet->GetActorLocation(), 55 * _planet->GetActorScale().X, FColor::Yellow, 2)
		DRAW_LINE(GetActorLocation(), _planet->GetActorLocation(), FColor::Red, 2)
	}
}

void ASpaceCraft::InitPlanetsScale(const FVector& _location)
{
	for (TObjectPtr<AActor> _planet : planets)
	{
		planetsScale.Add(_planet->GetActorScale());
	}
}

void ASpaceCraft::SetPlanetScale()
{
	FVector _location = GetActorLocation();
	for (size_t i = 0; i < planets.Num(); i++)
	{
		float _initDistance = FVector::Distance(initLocation, planets[i]->GetActorLocation());
		float _distance = FVector::Distance(_location, planets[i]->GetActorLocation());

		float _floatScale = (_initDistance - _distance) / 150;
		float _scale = planetsScale[i].X + _floatScale;
		_scale = _scale < 0.0f ? 0.0f : _scale;
		planets[i]->SetActorScale3D(FVector(_scale));
	}
}
