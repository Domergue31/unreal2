// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "TalosLink.h"
#include "TalosNode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class EXAMP2CORRECTION_API ATalosNode : public AStaticMeshActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere) FColor nodeColor = FColor::Red;
	UPROPERTY(VisibleAnywhere) TMap<FString, UTalosLink*> connectedNode = {};
	UPROPERTY(EditAnywhere) bool isSource = false;
	UPROPERTY(VisibleAnywhere) int id = 0;
	UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> validNodeLayer;
public:
	ATalosNode();
	FORCEINLINE void SetSource(const bool& _value) { isSource = _value; }
	FORCEINLINE int GetId() const { return id; }
	FORCEINLINE bool IsSource() const { return isSource; }
	UFUNCTION(BlueprintCallable) void AddLink(ATalosNode* _otherlink);
	virtual void NodeBehaviour();
protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
};
