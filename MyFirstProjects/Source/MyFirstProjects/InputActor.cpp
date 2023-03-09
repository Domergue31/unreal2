

#include "InputActor.h"
#include "Utils.h"
#include "InputUtils.h"

AInputActor::AInputActor()
{
    PrimaryActorTick.bCanEverTick = true;
    mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = mesh;
    mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
    mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("Material'/Engine/EditorMaterials/Cloth/CameraLitDoubleSided.CameraLitDoubleSided'")));
}


void AInputActor::BeginPlay()
{
	Super::BeginPlay();
    SetUpInput();
}

void AInputActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    DRAW_LINE(GetActorLocation() , GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 100, FColor::Red, 2)
    DRAW_SPHERE(GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 100, 20, FColor::Red, 2)
    DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorRightVector().GetSafeNormal() * 100, FColor::Green, 2)
    DRAW_SPHERE(GetActorLocation() + GetActorRightVector().GetSafeNormal() * 100, 20, FColor::Green, 2)
    DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorUpVector().GetSafeNormal() * 100, FColor::Blue, 2)
    DRAW_SPHERE(GetActorLocation() + GetActorUpVector().GetSafeNormal() * 100, 20, FColor::Blue, 2)
}

void AInputActor::SetUpInput()
{
    BIND_AXIS(HORIZONTAL, this, &AInputActor::SetHorizontal);
    BIND_AXIS(VERTICAL, this, &AInputActor::SetVertical);
    BIND_AXIS(ROTATION, this, &AInputActor::SetRotation);
}

void AInputActor::SetHorizontal(float _axis)
{
    const FVector _direction = GetActorRightVector().GetSafeNormal() * horizontalSpeed;
    SetActorLocation(GetActorLocation() + (_direction * _axis * DELTATIME));
}

void AInputActor::SetVertical(float _axis)
{
    const FVector _direction = GetActorForwardVector().GetSafeNormal() * verticalSpeed;
    SetActorLocation(GetActorLocation() + (_direction * _axis * DELTATIME));
}

void AInputActor::SetRotation(float _axis)
{
    AddActorLocalRotation(FRotator(0, rotateSpeed * _axis * DELTATIME, 0));
}