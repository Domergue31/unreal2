// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AICharacter.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "CustomAIController.generated.h"

/**
 * 
 */
UCLASS()
class BTEXO_API ACustomAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere) 
	TObjectPtr<UBehaviorTree> currentTree = nullptr;
	UPROPERTY(VisibleAnywhere) 
	TObjectPtr<APawn> controlledCharacter = nullptr;
	UPROPERTY(EditAnywhere) 
	FName patrolLocKeyName = "patrolLocation";
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector debugKeySelector;
	UPROPERTY(EditAnywhere)
	FName keyTarget = "target";
	UPROPERTY(EditAnywhere)
	FName keyDetected = "targetDetected";
	UPROPERTY(EditAnywhere)
	FName keyIsInRange = "isInRange";

public:
	FORCEINLINE FName GetKeyTarget() const { return keyTarget; }
	FORCEINLINE FName GetKeyDetected() const { return keyDetected; }
	FORCEINLINE FName GetKeyIsInRange() const { return keyIsInRange; }
	FORCEINLINE TObjectPtr<APawn> GetControlledPawn() { return controlledCharacter; }
	FORCEINLINE TObjectPtr<UBehaviorTree> GetCurrentTree() { return currentTree; }
	ACustomAIController();
	void SetTree(UBehaviorTree* _tree);
protected:
	void Init();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Debug();

public:
	UFUNCTION() void ReceiveTarget(AActor* _target);
	UFUNCTION() void ReceiveDetection(bool _detected);
	UFUNCTION() void ReceiveIsInRange(bool _value);

};
