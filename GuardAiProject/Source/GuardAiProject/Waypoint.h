// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "Waypoint.generated.h"

UCLASS()
class GUARDAIPROJECT_API AWaypoint : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<UBillboardComponent> icon = nullptr;
public:	
	AWaypoint();
};
