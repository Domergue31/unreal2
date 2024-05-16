// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Subsystems/WorldSubsystem.h"
#include "CWP_StreamingSourceComponent.h"
#include "CWP_StreamManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMWORLDPARTITION_API UCWP_StreamManagerSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
	TArray<UCWP_StreamingSourceComponent*> allSourcesComponent;
	TObjectPtr<ACWP_Octree> octree;



	FTimerHandle updateTimer;

public:
	FORCEINLINE void SetOctree(ACWP_Octree* _octree)
	{
		octree = _octree;
	}
	FORCEINLINE void Register(UCWP_StreamingSourceComponent* _streaming)
	{
		if (allSourcesComponent.Contains(_streaming)) return;
		allSourcesComponent.Add(_streaming);
	}
	FORCEINLINE void Unregister(UCWP_StreamingSourceComponent* _streaming)
	{
		if (!allSourcesComponent.Contains(_streaming)) return;
		allSourcesComponent.Remove(_streaming);
	}

public:
	UCWP_StreamManagerSubsystem();
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override { return TStatId(); }
private:
	void Update();
};
