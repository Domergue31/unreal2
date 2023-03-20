
#pragma once

#include "CoreMinimal.h"



#define BIND_AXIS(name, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);
#define BIND_ACTION(name, eventType, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAction(name, eventType, owner, method);

#define BIND_ACTION_PAWN(name, eventType, owner, method) PlayerInputComponent->BindAction(name, eventType, owner, method);


#define BIND(name, owner, method) name.AddDynamic(owner, method);

#define LERP(A, B, T) FMath::Lerp(A, B, T)


#define HORIZONTAL "Horizontal"
#define VERTICAL "Vertical"
#define ROTATIONYAW "RotationYaw"
#define RESPAWN "Respawn"
#define ROTATEPITCH "RotatePitch"
#define ROTATE "Rotate"
#define RESET "Reset"
#define UP "Up"
#define DOWN "Down"
#define RIGHT "Right"
#define LEFT "Left"
#define SELECT "Select"
