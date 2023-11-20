#include "CameraManagedComponent_C.h"
#include "MainGameMode.h"
#include "CameraManager_C.h"

UCameraManagedComponent_C::UCameraManagedComponent_C()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCameraManagedComponent_C::Enable()
{
	if (!cameraSystem)
		return;
	cameraSystem->SetActorTickEnabled(true);
}

void UCameraManagedComponent_C::Disable()
{
	if (!cameraSystem)
		return;
	cameraSystem->SetActorTickEnabled(false);
}

void UCameraManagedComponent_C::RegisterCamera(FString _id)
{
	id = _id;
	Init();
}


void UCameraManagedComponent_C::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UCameraManagedComponent_C::Init()
{
	cameraSystem = GetCameraMovementSystem();
	isManaged = GetManager()->AddCamera(this);
}

void UCameraManagedComponent_C::RemoveCamera()
{
	if (!isManaged)
		return;
	isManaged = !GetManager()->RemoveCamera(this);
}

UCameraManager_C* UCameraManagedComponent_C::GetManager()
{
	AMainGameMode* _gm = GetWorld()->GetAuthGameMode<AMainGameMode>();
	if (!_gm)
		return nullptr;
	return _gm->CameraManager();
}

ACameraMovements* UCameraManagedComponent_C::GetCameraMovementSystem() const
{
	return Cast<ACameraMovements>(GetOwner());
}

