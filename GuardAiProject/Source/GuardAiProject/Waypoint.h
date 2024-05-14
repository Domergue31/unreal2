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
	UPROPERTY(VisibleAnywhere) TObjectPtr<class APath> pathOwner = nullptr;
public:	
	AWaypoint();
	FORCEINLINE void SetPath(APath* _path) { pathOwner = _path; }
	FORCEINLINE TObjectPtr<APath> GetPathOwner() { return pathOwner; }
protected:
	virtual void BeginPlay() override;
};
