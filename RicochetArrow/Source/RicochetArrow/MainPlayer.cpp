#include "MainPlayer.h"
#include "Kismet/KismetSystemLibrary.h"
#include "InputUtils.h"

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");

	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TOWARD, this, &AMainPlayer::MoveForward);
	PlayerInputComponent->BindAxis(RIGHT, this, &AMainPlayer::MoveRight);
	PlayerInputComponent->BindAxis(CAMH, this, &AMainPlayer::MoveCameraHorizontal);
	PlayerInputComponent->BindAxis(CAMV, this, &AMainPlayer::MoveCameraVertical);

	PlayerInputComponent->BindAction(SHOOT, EInputEvent::IE_Pressed, this, &AMainPlayer::ShootArrow);
}

void AMainPlayer::MoveForward(float _axis)
{
	FVector _direction = GetActorForwardVector()  * movementSpeed * _axis;
	AddMovementInput(_direction);
}

void AMainPlayer::MoveRight(float _axis)
{
	FVector _direction = GetActorRightVector() * movementSpeed * _axis;
	AddMovementInput(_direction);
}

void AMainPlayer::MoveCameraVertical(float _axis)
{
	FRotator _newRot = arm->GetRelativeRotation() + FRotator(_axis, 0, 0);
	arm->SetRelativeRotation(_newRot);
}

void AMainPlayer::MoveCameraHorizontal(float _axis)
{
	AddControllerYawInput(_axis);
}

void AMainPlayer::ShootArrow()
{
	if (!ricochetSettings || !ricochetSettings->RicochetArrowRef())
		return;
	ARicochetArrowActor* _arrow = GetWorld()->SpawnActor<ARicochetArrowActor>(ricochetSettings->RicochetArrowRef(), GetActorLocation(), GetActorRotation());
	_arrow->SetPath(CalculateTraj());
}

TArray<FVector> AMainPlayer::CalculateTraj()
{
	FVector _origin = GetActorLocation();
	FVector _direction = GetActorForwardVector();
	FHitResult _result;
	bool _hit = false;
	TArray<FVector> _path;
	for (int i = 0; i < ricochetSettings->HitNumber(); i++)
	{
		_hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, _origin, _origin + _direction * ricochetSettings->Range(),
			ricochetSettings->ObjectsType(), true, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);
		if (_hit)
		{
			_path.Add(_origin = _result.ImpactPoint);
			_direction = _direction - 2 * (FVector::DotProduct(_direction, _result.ImpactNormal)) * _result.ImpactNormal;
		}
		else
		{
			_path.Add(_origin + _direction * ricochetSettings->Range());
			break;
		}
	}
	return _path;
}

