// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StreamingSourceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINIMAPTEST_API UStreamingSourceComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool enableStreamingSource = true;
	UPROPERTY(VisibleAnywhere)
	FString id;


public:
	FORCEINLINE bool IsEnableStreamingSource() const { return enableStreamingSource; }
	UStreamingSourceComponent();


protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
