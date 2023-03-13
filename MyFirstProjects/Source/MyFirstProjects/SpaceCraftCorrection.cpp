// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraftCorrection.h"
#include "InputUtils.h"
#include "Utils.h"

// Sets default values
ASpaceCraftCorrection::ASpaceCraftCorrection()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Game/Meshes/SpaceShip/source.source'")));
	mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Game/Meshes/SpaceShip/Material__31_026_Inst.Material__31_026_Inst'")));
}

// Called when the game starts or when spawned
void ASpaceCraftCorrection::BeginPlay()
{
	Super::BeginPlay();
	InitShip();
}

// Called every frame
void ASpaceCraftCorrection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DRAW_LINE(GetActorLocation() + shipVelocity, GetActorLocation(), FColor::Cyan, 2);
	DRAW_SPHERE(GetActorLocation() + shipVelocity, 15, FColor::Orange, 2);
	AddFloatingBehaviour();
}

void ASpaceCraftCorrection::InitShip()
{
	InitInput();
	if (!currentGalaxy)
		return;
	currentGalaxy->InitGalaxy(this);
}



void ASpaceCraftCorrection::InitInput()
{
	BIND_AXIS(VERTICAL, this, &ASpaceCraftCorrection::MoveForward)
	BIND_AXIS(HORIZONTAL, this, &ASpaceCraftCorrection::RotateShip)
	BIND_AXIS(VIEW, this, &ASpaceCraftCorrection::AddPitch)
}

void ASpaceCraftCorrection::MoveForward(float _axis)
{
	forwardVelocity = FMath::Lerp(forwardVelocity, FMath::Abs(_axis), DELTATIME * fwdWeight * speed);
	shipVelocity = GetActorForwardVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity);
}

void ASpaceCraftCorrection::RotateShip(float _axis)
{
	/*if (shipVelocity.Size() == 0)
		return;*/
	rotateAxis = FMath::Lerp(rotateAxis, _axis, DELTATIME * rotateWeight);
	AddActorLocalRotation(FRotator(0, rotateAxis * 10 * DELTATIME * speed, 0));
	const FRotator _bank = FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, bankAngle * rotateAxis), DELTATIME * speed);
	SetActorRotation(_bank);
}

void ASpaceCraftCorrection::AddFloatingBehaviour()
{
	if (shipVelocity.Size() > 0.1f)
		return;
	SetActorLocation(GetActorLocation() + FVector(0, 0, FMath::Sin(WORLD->TimeSeconds) * DELTATIME * 10));
}


void ASpaceCraftCorrection::AddPitch(float _axis)
{
	pitchAxis = FMath::Lerp(pitchAxis, _axis, DELTATIME * pitchWeight * speed);
	AddActorLocalRotation(FRotator(pitchAxis, 0, 0));
}
