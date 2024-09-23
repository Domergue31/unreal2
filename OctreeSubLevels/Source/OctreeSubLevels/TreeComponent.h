// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TreeComponent.generated.h"


class ATreeCell;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OCTREESUBLEVELS_API UTreeComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadStateChanged, bool, _state);

	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnLoadStateChanged onLoadStateChanged;

	UPROPERTY(VisibleAnywhere, Category="Octree")
		TObjectPtr<ATreeCell> owner = nullptr;
	UPROPERTY(EditAnywhere, Category="Octree")
		bool isCustomLoading = false;

public:
	FORCEINLINE FOnLoadStateChanged& OnLoadStateChanged() { return onLoadStateChanged; }
	UTreeComponent();
	FORCEINLINE bool GetIsCustomLoading() const { return isCustomLoading; }

protected:
	virtual void BeginPlay() override;
};
