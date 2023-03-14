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
	springArm = CreateDefaultSubobject<USpringArmComponent>("CameraAnchor");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	//
	customTimer = CreateDefaultSubobject<UTimerComponent>("Timer");
	AddOwnedComponent(customTimer);
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
	RotateAroundCamera();
	ResetCameraRotation();
}

void ASpaceCraftCorrection::InitShip()
{
	InitInput();
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
	if (!currentGalaxy)
		return;
	currentGalaxy->InitGalaxy(this);
	if (customTimer)
	{
		BIND(customTimer->OnTimerEnd(), this, &ASpaceCraftCorrection::PassiveModeEnable)
		customTimer->StartTimer();
	}
	initRotation = springArm->GetRelativeRotation();
	BIND(onShipMovement, this, &ASpaceCraftCorrection::MovingDetection)
	BIND(onShipAxis, customTimer, &UTimerComponent::ResetTimer)
	BIND(onShipAxis, this, &ASpaceCraftCorrection::PassiveModeDisable)
	springSnapshot = FSpringArmMemory(springArm);
}



void ASpaceCraftCorrection::InitInput()
{
	BIND_AXIS(VERTICAL, this, &ASpaceCraftCorrection::MoveForward)
	BIND_AXIS(HORIZONTAL, this, &ASpaceCraftCorrection::RotateShip)
	BIND_AXIS(VIEW, this, &ASpaceCraftCorrection::AddPitch)
}

void ASpaceCraftCorrection::MoveForward(float _axis)
{
	onShipMovement.Broadcast(_axis);
	forwardVelocity = FMath::Lerp(forwardVelocity, FMath::Abs(_axis), DELTATIME * fwdWeight * speed);
	shipVelocity = GetActorForwardVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity);
}

void ASpaceCraftCorrection::RotateShip(float _axis)
{
	onShipMovement.Broadcast(_axis);
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
	onShipMovement.Broadcast(_axis);
	pitchAxis = FMath::Lerp(pitchAxis, _axis, DELTATIME * pitchWeight * speed);
	AddActorLocalRotation(FRotator(pitchAxis, 0, 0));
}

void ASpaceCraftCorrection::SetRandomPassiveValues()
{
	springArm->TargetArmLength =
		passiveModeSettings.GetRandomlenght();
	springArm->SocketOffset += FVector(0, 0,
		passiveModeSettings.GetRandomHeight());
}

#pragma region PassiveMode
void ASpaceCraftCorrection::RotateAroundCamera()
{
	if (!springArm || !passiveModeEnable)
		return;
	springArm->AddRelativeRotation(FRotator(0, passiveModeYawSpeed * DELTATIME, 0));
}

void ASpaceCraftCorrection::ResetCameraRotation()
{
	if (!springArm || passiveModeEnable)
		return;
	springArm->SetRelativeRotation(LERP(springArm->GetRelativeRotation(), initRotation, DELTATIME * 5));
}

void ASpaceCraftCorrection::PassiveModeEnable()
{
	passiveModeEnable = true;
	SetRandomPassiveValues();

}

void ASpaceCraftCorrection::PassiveModeDisable()
{
	passiveModeEnable = false;
	springSnapshot.ResetValues(springArm);
}

void ASpaceCraftCorrection::MovingDetection(float _value)
{
	isMoving = FMath::Abs(_value) > 0;
	if (isMoving)
		onShipAxis.Broadcast();

}

#pragma endregion PassiveMode
