

#include "IceCubeActor.h"

AIceCubeActor::AIceCubeActor()
{
	PrimaryActorTick.bCanEverTick = true; 
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	//mesh->SetMaterial(0, LoadObject<UMaterial>(this, TEXT("'/Content/Materials/NewMaterial_Inst.NewMaterial_Inst'")));
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	movement = CreateDefaultSubobject< UActorMovementCorrComponent>("Movement");
	AddOwnedComponent(movement);

}

void AIceCubeActor::BeginPlay()
{
	Super::BeginPlay();
	InitIceCube();
}

void AIceCubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	settings.UpdateScaleTimer(WORLD);
	settings.UpdateScale(this);
	ScaleBehaviour();
	DRAW_BOX(GetActorLocation(), settings.TargetSize() * 50, FColor::Red, 2);
	DRAW_BOX(GetActorLocation(), settings.initSize * 50, FColor::Red, 2);
}

void AIceCubeActor::InitIceCube()
{
	BindInput();
	WORLD->GetFirstPlayerController()->SetViewTarget(this);
	settings.initSize = GetActorScale();
}

void AIceCubeActor::BindInput()
{
	BIND_AXIS(VERTICAL, movement.Get(), &UActorMovementCorrComponent::MoveForward);
	BIND_AXIS(HORIZONTAL, movement.Get(), &UActorMovementCorrComponent::MoveHorizontal);
	BIND_AXIS(ROTATE, movement.Get(), &UActorMovementCorrComponent::Rotate);
	BIND_ACTION(RESET, EInputEvent::IE_Pressed, movement.Get(), &UActorMovementCorrComponent::CallReset);
}

void AIceCubeActor::ScaleBehaviour()
{
	if (!movement)
		return;
	movement->UpdateForwardWeight( 1 - settings.ScaleRatio() + 0.1f);
	movement->UpdateHorizontalWeight(1 - settings.ScaleRatio() + 0.1f);
	movement->UpdateRotateWeight(1 - settings.ScaleRatio() + 0.1f);
}