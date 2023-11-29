
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "Corr_DiabloCharacter.generated.h"

UCLASS()
class SCREENWORLD_API ACorr_DiabloCharacter : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Diablo")
	TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere, Category="Diablo")
	TObjectPtr<USpringArmComponent> arm = nullptr;
	UPROPERTY(EditAnywhere, Category = "Diablo", meta = (UIMin = 50, ClampMin = 50)) float minRange = 50;
	UPROPERTY(EditAnywhere, Category="Diablo")
	TArray<TEnumAsByte<EObjectTypeQuery>> interactLayer;
	UPROPERTY()
	TArray<AActor*> actorIgnore = { this };
	UPROPERTY(EditAnywhere, Category="Diablo|Inputs")
	TSoftObjectPtr<UInputMappingContext> context = nullptr;
	UPROPERTY(EditAnywhere, Category="Diablo|Inputs")
	TObjectPtr<UInputAction> inputMouseAction = nullptr;

	FVector destination;
public:
	ACorr_DiabloCharacter();
	FORCEINLINE bool IsAtLocation() const { return FVector::Distance(GetActorLocation(), destination) < minRange; }
protected:
	void InitInput();
	void MoveTo(float _delta);
	void RotateTo(float _delta);
	void GetTargetLocation();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
