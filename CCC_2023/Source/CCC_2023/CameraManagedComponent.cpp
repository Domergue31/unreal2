


#include "CameraManagedComponent.h"
#include "MainGameMode.h"

UCameraManagedComponent::UCameraManagedComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCameraManagedComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("register component"))
	AMainGameMode* _gm = GetWorld()->GetAuthGameMode<AMainGameMode>();
}

