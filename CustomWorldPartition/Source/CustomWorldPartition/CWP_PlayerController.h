#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CWP_PlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* mappingContext;

private:
	virtual void BeginPlay() override;
};