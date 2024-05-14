// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "StreamingSourceComponent.h"
#include "RecordCamera.h"
#include "StreamingSourceManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MINIMAPTEST_API UStreamingSourceManagerSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<UStreamingSourceComponent*> allStreamingSources;


	UPROPERTY()
	TObjectPtr<ARecordCamera> miniMapCamera = nullptr;
	UPROPERTY()
	TObjectPtr<class ACustomWorldSettings> worldSettings = nullptr;


	float maxTime = 0.2f;
	float currentTime = 0;
	float canTick = true;



public:
	FORCEINLINE TObjectPtr<ARecordCamera> GetMiniMapCamera() const { return miniMapCamera; }
	FORCEINLINE TArray<UStreamingSourceComponent*> GetAll() const { return allStreamingSources; }
	UStreamingSourceManagerSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override { return TStatId(); }
	//virtual TStatId GetStatId() const override PURE_VIRTUAL(UTickableWorldSubsystem::GetStatId, return TStatId(););
public:
	bool Register(UStreamingSourceComponent* _source);
	bool Unregister(UStreamingSourceComponent* _source);
	//UStreamingSourceComponent* Get(const FString& _nameID) const;

private:
	void ComputeCameraPosition();
	void UpdateTimer();
};
