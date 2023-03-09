// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActor.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API AInputActor : public AActor
{
	GENERATED_BODY()


		UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
			float horizontalSpeed = 50;
	UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
			float verticalSpeed = 50;
	UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
		float rotaSpeed = 25;
	UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
		float blowUpSpeed = 0.5f;
	UPROPERTY(EditAnywhere, Category = Scale)
		FVector scale = FVector(0);
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
	void BlowUp(float _axis);
};

