// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActor.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API AInputActor : public AActor
{
	GENERATED_BODY()


		UPROPERTY(EditAnywhere, Category = "Movement", meta = (UIMin = 0, ClampMin = 0))
			float horizontalSpeed = 50;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (UIMin = 0, ClampMin = 0))
			float verticalSpeed = 50;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (UIMin = 0, ClampMin = 0))
		float rotaSpeed = 25;

	FVector targetScale, scale , initLocation;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (UIMin = 0, ClampMin = 0))
		float scaleSpeed = 5;



	
	UPROPERTY(EditAnywhere, Category = "Movement|MyWork", meta = (UIMin = 0, ClampMin = 0))
		float blowUpSpeed = 5;
		UPROPERTY(EditAnyWhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	
public:	
	AInputActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void SetUpInput();
	void SetHorizontal(float _axis);
	void SetVertical(float _axis);
	void SetRotation(float _axis);
	void SetDynamicScale(float _axis);
	void UpdateScale(const float& _speed);

	void Respawn();
	void BlowUp(float _axis);
	void BlowUp_Interp(FVector _from, FVector _to);
};

