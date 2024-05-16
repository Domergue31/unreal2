#pragma once
#include "CoreMinimal.h"

#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include "GameFramework/Character.h"
#include "CWP_Player.generated.h"

#define LOG_S(text, string) UE_LOG(LogTemp, Warning, TEXT(text), *string)

USTRUCT()
struct FCharacterInput
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> inputMapping;

	UPROPERTY(EditAnywhere, Category = "Actions")
	UInputAction* movement;

	UPROPERTY(EditAnywhere, Category = "Actions")
	UInputAction* sprint;

	UPROPERTY(EditAnywhere, Category = "Actions")
	UInputAction* rotation;
};

class UCWP_MovementComponent;
class UCWP_SightComponent;
class UCWP_StreamingSourceComponent;

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_Player : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UCameraComponent> camera;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UCWP_MovementComponent> movement;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UCWP_StreamingSourceComponent> streamingSource = nullptr;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UCWP_SightComponent> sight = nullptr;

	UPROPERTY(EditAnywhere, Category = "Inputs")
	FCharacterInput inputs = FCharacterInput();

public:
	ACWP_Player();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void InitInputs();
};