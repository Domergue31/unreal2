
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConversationCamera.h"
#include "ConversationSettings.h"
#include "PNJActor.generated.h"

UCLASS()
class PNJCAMERAPROJECT_API APNJActor : public AActor
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConversationStart, APNJActor*, _pnj);

	UPROPERTY(BlueprintAssignable, BlueprintCallable, meta = (AllowPrivateAccess))
		FOnConversationStart onConversationStart;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AConversationCamera> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UConversationSettings> settings = nullptr;
	UPROPERTY(EditANywhere, Category="Debug")
		bool useDebug = true;

public:	
	APNJActor();
	FORCEINLINE FOnConversationStart& OnConversationStart() { return onConversationStart; }
	FORCEINLINE UConversationSettings* Settings() const { return settings; }

	FORCEINLINE FVector GetTargetFinalPosition() const { return GetActorLocation() + GetActorForwardVector() * settings->Distance(); }
	FORCEINLINE FVector GetCameraFinalPosition() { return camera->FinalPosition(this); }
	FORCEINLINE FVector GetCenterPosition() const { return GetActorLocation() + GetActorForwardVector() * (settings->Distance() / 2); }
protected:
	virtual void BeginPlay() override;
	void MoveTarget();
	virtual void Tick(float DeltaTime) override;

	void ShowDebug();
private:
	bool ShouldTickIfViewportsOnly() const;
	bool VerifPosition();
};
