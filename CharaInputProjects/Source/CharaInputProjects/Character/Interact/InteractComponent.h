// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractItem.h"
#include "InputMappingContext.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARAINPUTPROJECTS_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Interact") TArray<TEnumAsByte<EObjectTypeQuery>> interactLayer;
	UPROPERTY(EditAnywhere, Category = "Interact", meta = (UIMin = 100, ClampMin = 100)) float interactRange = 300;
	UPROPERTY(EditAnywhere, Category = "Interact", meta = (UIMin = 0, ClampMin = 0)) float interactHeight = 100;

	UPROPERTY() TObjectPtr<AInteractItem> currentItem = nullptr;
	UPROPERTY() TObjectPtr<AInteractItem> detectedItem = nullptr;

	bool canGrabItem = false;
	FHitResult result;

public:	
	UInteractComponent();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void DetectObject();
	void DetectObjetcFeedback(TObjectPtr<AActor> _item);
public:
	void GrabObject(const FInputActionValue& _value);
	void DropObject(const FInputActionValue& _value);
		
};
