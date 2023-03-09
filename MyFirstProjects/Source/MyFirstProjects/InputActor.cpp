

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
    scale = GetActorScale();
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
    BIND_AXIS(BLOW_UP, this, &AInputActor::BlowUp);
}

void AInputActor::SetHorizontal(float _axis)
{
    const FVector _direction = GetActorRightVector().GetSafeNormal() * horizontalSpeed;
    SetActorLocation(GetActorLocation() + (_direction * _axis * DELTATIME * horizontalSpeed));
}

void AInputActor::SetVertical(float _axis)
{
    const FVector _direction = GetActorForwardVector().GetSafeNormal() * verticalSpeed;
    SetActorLocation(GetActorLocation() + (_direction * _axis * DELTATIME * verticalSpeed));
}

void AInputActor::SetRotation(float _axis)
{
    AddActorLocalRotation(FRotator(0, _axis * rotaSpeed * DELTATIME, 0));
}

void AInputActor::BlowUp(float _axis)
{
    if (_axis >= 1.0f)
    {
        BlowUp_Interp(GetActorScale(), scale * 2);
    }
    else if (_axis <= -1.0f)
    {
        BlowUp_Interp(GetActorScale(), scale / 2);
    }
    else
    {
        BlowUp_Interp(GetActorScale(), scale);
    }
}

void AInputActor::BlowUp_Interp(FVector _from, FVector _to)
{
    const FVector _result = FMath::VInterpConstantTo(_from, _to, DELTATIME, blowUpSpeed);
    SetActorScale3D(_result);
}
