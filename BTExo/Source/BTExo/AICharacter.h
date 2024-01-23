// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AICharacter.generated.h"

UCLASS()
class BTEXO_API AAICharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere) TObjectPtr<UBehaviorTree> tree = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<class ACustomAIController> aiController = nullptr;

public:
	AAICharacter();
	FORCEINLINE UBehaviorTree* GetTree() { return tree; }
protected:
	virtual void BeginPlay() override;

};
