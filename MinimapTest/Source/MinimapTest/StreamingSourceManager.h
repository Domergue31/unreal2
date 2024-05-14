// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StreamingSourceComponent.h"
#include "RecordCamera.h"
#include "StreamingSourceManager.generated.h"

UCLASS()
class MINIMAPTEST_API AStreamingSourceManager : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	TArray<UStreamingSourceComponent*> allStreamingSources;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<ARecordCamera> miniMapCamera = nullptr;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class ACustomWorldSettings> worldSettings = nullptr;


	float maxTime = 0.2f;
	float currentTime = 0;
	float canTick = true;



public:
	FORCEINLINE TObjectPtr<ARecordCamera> GetMiniMapCamera() const { return miniMapCamera; }
	FORCEINLINE TArray<UStreamingSourceComponent*> GetAll() const { return allStreamingSources; }
	AStreamingSourceManager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	bool Register(UStreamingSourceComponent* _source);
	bool Unregister(UStreamingSourceComponent* _source);

private:
	void ComputeCameraPosition();
	void UpdateTimer();
};
