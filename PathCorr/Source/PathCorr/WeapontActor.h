// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "WeapontActor.generated.h"

UCLASS()
class PATHCORR_API AWeapontActor : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UBillboardComponent> icon = nullptr;
public:	
	AWeapontActor();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
