// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "WeapontActor.h"
#include "PathhManager.h"
#include "PathActor.generated.h"

UCLASS()
class PATHCORR_API APathActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UBillboardComponent> icon = nullptr;
	UPROPERTY(EditAnywhere)
		TArray<AWeapontActor*> waypoints;
	UPROPERTY(EditAnywhere)
		FName pathName = "Path";
	UPROPERTY(EditAnywhere)
		FColor pathColor = FColor::Green;

	bool isConnected = false;
public:	
	APathActor();
	FORCEINLINE FName GetPathName() const { return pathName; }
	FORCEINLINE FVector getNextWaypoint(const int& _index)
	{
		if (_index < 0 || _index > waypoints.Num() - 1)
			return GetActorLocation();
		return waypoints[_index] ? waypoints[_index]->GetActorLocation() : GetActorLocation();
	}
	FORCEINLINE int GetWaypointCount() const { return waypoints.Num(); }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawPath();
	TObjectPtr<UPathhManager> GetPathManager();
};
