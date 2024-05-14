// Fill out your copyright notice in the Description page of Project Settings.


#include "StreamingSourceManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RecordCameraManagerSubsystem.h"
#include "CustomWorldSettings.h"

AStreamingSourceManager::AStreamingSourceManager()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void AStreamingSourceManager::BeginPlay()
{
	Super::BeginPlay();
	worldSettings = Cast<ACustomWorldSettings>(GetWorld()->GetWorldSettings());
}

void AStreamingSourceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateTimer();
}

bool AStreamingSourceManager::Register(UStreamingSourceComponent* _source)
{
	if (allStreamingSources.Contains(_source))
		return false;
	allStreamingSources.Add(_source);
	return true;
}

bool AStreamingSourceManager::Unregister(UStreamingSourceComponent* _source)
{
	if (!allStreamingSources.Contains(_source))
		return false;
	allStreamingSources.Remove(_source);
	return true;
}

void AStreamingSourceManager::ComputeCameraPosition()
{
	if (!miniMapCamera)
	{
		miniMapCamera = GetWorld()->GetGameInstance()->GetSubsystem<URecordCameraManagerSubsystem>()->Get("MiniMap");
		return;
	}

	float _x = 0;
	float _y = 0;
	float _currentDistance = UE_MAX_FLT;
	const int _size = allStreamingSources.Num();
	for (int _index = 0; _index < _size; _index++)
	{
		_x += allStreamingSources[_index]->GetOwner()->GetActorLocation().X;
		_y += allStreamingSources[_index]->GetOwner()->GetActorLocation().Y;
		for (int _i = _index + 1; _i < _size; _i++)
		{
			float _newDist = FVector2D::Distance(FVector2D(allStreamingSources[_i - 1]->GetOwner()->GetActorLocation()), FVector2D(allStreamingSources[_i]->GetOwner()->GetActorLocation()));
			_currentDistance = _currentDistance > _newDist ? _newDist : _currentDistance;
		}
	}
	if (_size == 0)
		miniMapCamera->SetDestination(FVector(0, 0, worldSettings->GetBaseHeight() + _currentDistance * worldSettings->GetDepthScale()));
	else if (_size == 1)
	{
		UKismetSystemLibrary::PrintString(this, FVector(_x / _size, _y / _size, worldSettings->GetBaseHeight() + 1000 * worldSettings->GetDepthScale()).ToString(), true, true, FLinearColor(FColor::Magenta), 1);
		miniMapCamera->SetDestination(FVector(_x / _size, _y / _size, worldSettings->GetBaseHeight() + 1000 * worldSettings->GetDepthScale()));
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, FVector(_x / _size, _y / _size, worldSettings->GetBaseHeight() + _currentDistance * worldSettings->GetDepthScale()).ToString(), true, true, FLinearColor(FColor::Magenta), 1);
		miniMapCamera->SetDestination(FVector(_x / _size, _y / _size, worldSettings->GetBaseHeight() + _currentDistance * worldSettings->GetDepthScale()));
	}
}

void AStreamingSourceManager::UpdateTimer()
{
	if (!canTick) return;
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime >= maxTime)
	{
		ComputeCameraPosition();
		currentTime = 0;
	}
}
