// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Waypoint.h"
#include "../Path.h"
#include "WaypointManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GUARDAIPROJECT_API UWaypointManager : public UObject
{
	GENERATED_BODY()
	

	UPROPERTY(VisibleAnywhere) TArray<AWaypoint*> points = TArray<AWaypoint*>();

public:
	bool Register(AWaypoint* _path);
	bool UnRegister(AWaypoint* _path);

	AWaypoint* GetNearestPoint(FVector _pos);
};
