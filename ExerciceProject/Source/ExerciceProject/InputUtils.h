// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#define BIND_AXIS(name, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);
#define BIND_ACTION(name, eventType, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAction(name, eventType, owner, method);

#define BIND(name, owner, method) name.AddDynamic(owner, method);

#define LERP(A, B, T) FMath::Lerp(A, B, T)


#define HORIZONTAL "Horizontal"
#define VERTICAL "Vertical"
#define ROTATIONYAW "RotationYaw"
#define RESPAWN "Respawn"
