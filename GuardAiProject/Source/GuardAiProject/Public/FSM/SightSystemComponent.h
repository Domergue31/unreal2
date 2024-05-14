// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SightSystemAsset.h"
#include "SightSystemComponent.generated.h"




UCLASS( Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUARDAIPROJECT_API USightSystemComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere) TObjectPtr<USightSystemAsset> sightData = nullptr;
	UPROPERTY(EditAnywhere, meta = (AllowAbstract = "true")) TSubclassOf<AActor> test = nullptr;
	//UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMIn = 0, UMax = 360, ClampMax = 360)) int sightAngle = 90;
	//UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMIn = 0)) int range = 500;
	//UPROPERTY(EditAnywhere, meta = (UMin = 1, ClampMIn = 1)) int definition = 1;
	//UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> layers;

	UPROPERTY(VisibleAnywhere) TObjectPtr<AActor> targetSight = nullptr;
private:
	//UPROPERTY(EditAnywhere) float sightHeight = 0;


public:
	FORCEINLINE TObjectPtr<AActor> TargetSight() { return targetSight; }
	FORCEINLINE FVector GetSightHeightLocation() const { return GetOwner()->GetActorLocation() + FVector(0, sightData->GetSightHeight(), 0); }
	FORCEINLINE FVector GetOwnerLocation() const { return GetOwner()->GetActorLocation(); }
	USightSystemComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void UpdateSight();

	void ClearSight();
		
};
