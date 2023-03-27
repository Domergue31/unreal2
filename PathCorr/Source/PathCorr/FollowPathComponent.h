// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PathCorrGameModeBase.h"
#include "PathActor.h"
#include "FollowPathComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATHCORR_API UFollowPathComponent : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere)
		TObjectPtr<APathActor> currentPath = nullptr;
	UPROPERTY(EditAnywhere)
		float minimalRange = 100;
	UPROPERTY(EditAnywhere)
		float moveSpeed = 100;
	int navIndex = 0;
	bool canFollowPath = true;
public:	
	UFollowPathComponent();
	FORCEINLINE FVector GetOwnerLocation() { return GetOwner()->GetActorLocation(); }
	FORCEINLINE bool IsAtLocation(const FVector& _location) { return FVector::Distance(GetOwnerLocation(), _location) < minimalRange; }
	void StartFollow();
	void StopFollow();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	void MoveAlongPath();
	TObjectPtr<UPathhManager> GetPathManager();
};
