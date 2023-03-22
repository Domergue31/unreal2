// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataObject.h"
#include "MyActor.generated.h"

UCLASS()
class CHARACTEREXCORR_API AMyActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UDataObject> data = nullptr;
	UPROPERTY()
		TObjectPtr<class AMainCharacter> copy = nullptr;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AMainCharacter> originalToCopy = nullptr;

public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type) override;
};
