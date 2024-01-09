// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMObject.h"
#include "Components/ActorComponent.h"
#include "FSMComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIPROJECT_API UFSMComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<UFSMObject> currentFSMType = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<UFSMObject> runningFSM = nullptr;
public:	
	UFSMComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(EEndPlayReason::Type _end) override;
	void CloseFSM();
	void Init();
	void UpdateFSM();
		
};
