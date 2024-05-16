#pragma once
#include "CoreMinimal.h"

#include "CWP_Player.h"
#include "InputActionValue.h"

#include "Components/ActorComponent.h"
#include "CWP_MovementComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta = (BlueprintSpawnableComponent) )
class CUSTOMWORLDPARTITION_API UCWP_MovementComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool canMove = true;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool isSprinting = false;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0", ClampMax = "10000.0"))
	float moveSpeed = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0", ClampMax = "10000.0"))
	float sprintSpeed = 15.0f;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool canRotate = true;

	UPROPERTY()
	APawn* pawn = nullptr;

	UPROPERTY()
	ACharacter* character = nullptr;

public:
	FORCEINLINE APawn* GetPawn()
	{
		if (!pawn)
		{
			pawn = Cast<APawn>(GetOwner());
		}

		return pawn;
	}
	FORCEINLINE ACharacter* GetCharacter()
	{
		if (!character)
		{
			character = Cast<ACharacter>(GetOwner());
		}

		return character;
	}

public:	
	UCWP_MovementComponent();

private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION() void Move(const FInputActionValue& _value);
	UFUNCTION() void Sprint(const FInputActionValue& _value);
	UFUNCTION() void Rotate(const FInputActionValue& _value);
};