// Fill out your copyright notice in the Description page of Project Settings.


#include "StreamingSourceManagerSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RecordCameraManagerSubsystem.h"
#include "CustomWorldSettings.h"


UStreamingSourceManagerSubsystem::UStreamingSourceManagerSubsystem()
{
	
}

void UStreamingSourceManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	//UKismetSystemLibrary::PrintString(this, "Initialize StreamingManager", true, true, FLinearColor(FColor::Magenta), 1);
	//worldSettings = Cast<ACustomWorldSettings>(GetWorld()->GetWorldSettings());

}

void UStreamingSourceManagerSubsystem::Deinitialize()
{

	Super::Deinitialize();
	//UKismetSystemLibrary::PrintString(this, "Deinitialize StreamingManager", true, true, FLinearColor(FColor::Magenta), 1);
}

void UStreamingSourceManagerSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UpdateTimer();
}

bool UStreamingSourceManagerSubsystem::Register(UStreamingSourceComponent* _source)
{
	if (allStreamingSources.Contains(_source))
		return false;
	allStreamingSources.Add(_source);
	return true;
}

bool UStreamingSourceManagerSubsystem::Unregister(UStreamingSourceComponent* _source)
{
	if (!allStreamingSources.Contains(_source))
		return false;
	allStreamingSources.Remove(_source);
	return true;
}

//UStreamingSourceComponent* UStreamingSourceManagerSubsystem::Get(const FString& _nameID) const
//{
//	if (!allStreamingSources.Contains(_nameID))
//		return nullptr;
//	return allStreamingSources[_nameID];
//}

//TArray<UStreamingSourceComponent*> UStreamingSourceManagerSubsystem::GetAll() const
//{
//	TArray<UStreamingSourceComponent*> _sources;
//	for (TTuple<FString, UStreamingSourceComponent*> _pair : allStreamingSources)
//		_sources.Add(_pair.Value);
//	return _sources;
//}

void UStreamingSourceManagerSubsystem::ComputeCameraPosition()
{
	if (IsInitialized() && !miniMapCamera && GetWorld()->IsPlayInEditor())
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
	else
	{
		UKismetSystemLibrary::PrintString(this, FVector(_x / _size, _y / _size, worldSettings->GetBaseHeight() + _currentDistance * worldSettings->GetDepthScale()).ToString(), true, true, FLinearColor(FColor::Magenta), 1);
		miniMapCamera->SetDestination(FVector(_x / _size, _y / _size, worldSettings->GetBaseHeight() + _currentDistance * worldSettings->GetDepthScale()));
	}
}

void UStreamingSourceManagerSubsystem::UpdateTimer()
{
	if (!canTick) return;
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime >= maxTime)
	{
		ComputeCameraPosition();
		currentTime = 0;
	}
}

