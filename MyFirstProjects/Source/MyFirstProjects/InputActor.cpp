

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
    initLocation = GetActorLocation();
    SetUpInput();
}

void AInputActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 100, FColor::Red, 2)
    DRAW_SPHERE(GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 100, 20, FColor::Red, 2)
    DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorRightVector().GetSafeNormal() * 100, FColor::Green, 2)
    DRAW_SPHERE(GetActorLocation() + GetActorRightVector().GetSafeNormal() * 100, 20, FColor::Green, 2)
    DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorUpVector().GetSafeNormal() * 100, FColor::Blue, 2)
    DRAW_SPHERE(GetActorLocation() + GetActorUpVector().GetSafeNormal() * 100, 20, FColor::Blue, 2)
    DRAW_SPHERE(initLocation, 50, FColor::Cyan, 2)
    DRAW_LINE(initLocation, GetActorLocation(), FColor::Cyan, 2)
    UpdateScale(scaleSpeed);
}

void AInputActor::SetUpInput()
{
    BIND_AXIS(HORIZONTAL, this, &AInputActor::SetHorizontal);
    BIND_AXIS(VERTICAL, this, &AInputActor::SetVertical);
    BIND_AXIS(ROLLROTATION, this, &AInputActor::SetRotation);
    BIND_AXIS(SCALE, this, &AInputActor::SetDynamicScale);
    BIND_ACTION(RESPAWN, EInputEvent::IE_Pressed, this, &AInputActor::Respawn)
    //BIND_AXIS(BLOW_UP, this, &AInputActor::BlowUp);
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

void AInputActor::SetDynamicScale(float _axis)
{
    if (_axis == 0)
        targetScale = scale;
    else if (_axis > 0)
        targetScale = scale * 2;
    else if (_axis < 0)
        targetScale = scale / 2;
}

void AInputActor::UpdateScale(const float& _speed)
{
    const FVector _scale = FMath::Lerp(GetActorScale(), targetScale, DELTATIME * _speed);
    SetActorScale3D(_scale);
}





#pragma region My_Work
void AInputActor::Respawn()
{
    SetActorLocation(initLocation);
}

void AInputActor::BlowUp(float _axis)
{
    FVector actualScale = GetActorScale();
    if (_axis >= 1.0f)
        BlowUp_Interp(actualScale, scale * 2);
    else if (_axis <= -1.0f)
        BlowUp_Interp(actualScale, scale / 2);
    else
        BlowUp_Interp(actualScale, scale);
}

void AInputActor::BlowUp_Interp(FVector _from, FVector _to)
{
    const FVector _result = FMath::VInterpConstantTo(_from, _to, DELTATIME, blowUpSpeed);
    SetActorScale3D(_result);
}
#pragma endregion My_Work