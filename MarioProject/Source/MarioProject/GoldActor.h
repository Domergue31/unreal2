// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Elements.h"
#include "GoldActor.generated.h"

UCLASS()
class MARIOPROJECT_API AGoldActor : public AElements
{
	GENERATED_BODY()
	
public:	
	AGoldActor();
	void Init(const float& _lifeSpan, class AMarioProjectCharacter* _char);
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other) override;
};
