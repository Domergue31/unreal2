// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraActorOrbit.h"
#include "CameraSettingsOrbit.h"
#include <Kismet/KismetMathLibrary.h>
#include <format>

ACameraActorOrbit::ACameraActorOrbit()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACameraActorOrbit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraActorOrbit::UpdateCameraPosition()
{
	SetActorLocation(GetFinalLocation());
}

void ACameraActorOrbit::DrawDebug()
{
	ACameraActorMovement::DrawDebug();
}

FVector ACameraActorOrbit::RotationPoint()
{
	TObjectPtr<UCameraSettingsOrbit> _set = Cast<UCameraSettingsOrbit>(cameraSettings);
	const float _radius = _set ? _set->GetRadius() : 1;
	angle = ComputeAngle();
	float _x = FMath::Cos(FMath::DegreesToRadians(angle)) * _radius,
		  _y = FMath::Sin(FMath::DegreesToRadians(angle)) * _radius;
	return FVector(_x, _y, 0);
}

float ACameraActorOrbit::ComputeAngle()
{
	float _x = (FMath::Fmod(GetWorld()->TimeSeconds / Cast<UCameraSettingsOrbit>(cameraSettings)->GetDuration(), 1));
	//return 1 - UKismetMathLibrary::Cos((_x * UKismetMathLibrary::GetPI()) / 2) *360;

	return EaseOutBounce(_x);

	//return EaseInOutBounce(_x);

	//return EaseOutElastic(_x);
}

float ACameraActorOrbit::EaseInOutBounce(float _x)
{
	float a = 1 - 2 * _x;
	float b = 2 * _x - 1;
	return _x < 0.5
		? (1 - EaseOutBounce(a)) / 2
		: (1 + EaseOutBounce(b)) / 2;
}

float ACameraActorOrbit::EaseOutElastic(float _x)
{
	const float c4 = (2 * UKismetMathLibrary::GetPI()) / 3;

	return _x == 0
		? 0
		: _x == 1
		? 1
		: FMath::Pow(2, -10 * _x) * FMath::Sin((_x * 10 - 0.75) * c4) + 1;
}

float ACameraActorOrbit::EaseOutBounce(float& _x)
{
	const float n1 = 7.5625;
	const float d1 = 2.75;

	if (_x < 1 / d1) {
		return (n1 * _x * _x) * 360;
	}
	else if (_x < 2 / d1) {
		return (n1 * (_x -= 1.5 / d1) * _x + 0.75) * 360;
	}
	else if (_x < 2.5 / d1) {
		return (n1 * (_x -= 2.25 / d1) * _x + 0.9375) * 360;
	}
	else {
		return (n1 * (_x -= 2.625 / d1) * _x + 0.984375) * 360;
	}
}
