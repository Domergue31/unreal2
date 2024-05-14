// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "RecordCamera.h"
#include "RecordCameraManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MINIMAPTEST_API URecordCameraManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	TMap<FString, ARecordCamera*> recordCameras;

public:
	URecordCameraManagerSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	bool Register(const FString& _nameID, ARecordCamera* _source);
	bool Unregister(const FString& _nameID);
	ARecordCamera* Get(const FString& _nameID) const;
	TArray<ARecordCamera*> GetAll() const;
};
