// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordCameraManagerSubsystem.h"

URecordCameraManagerSubsystem::URecordCameraManagerSubsystem()
{
}

void URecordCameraManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

}

void URecordCameraManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();

}

bool URecordCameraManagerSubsystem::Register(const FString& _nameID, ARecordCamera* _source)
{
	if (recordCameras.Contains(_nameID))
		return false;
	recordCameras.Add(_nameID, _source);
	return true;
}

bool URecordCameraManagerSubsystem::Unregister(const FString& _nameID)
{
	if (!recordCameras.Contains(_nameID))
		return false;
	recordCameras.Remove(_nameID);
	return true;
}

ARecordCamera* URecordCameraManagerSubsystem::Get(const FString& _nameID) const
{
	if (!recordCameras.Contains(_nameID))
		return nullptr;
	return recordCameras[_nameID];
}

TArray<ARecordCamera*> URecordCameraManagerSubsystem::GetAll() const
{
	TArray<ARecordCamera*> _sources;
	for (TTuple<FString, ARecordCamera*> _pair : recordCameras)
		_sources.Add(_pair.Value);
	return _sources;
}
