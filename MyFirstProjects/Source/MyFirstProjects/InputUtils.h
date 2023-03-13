// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*
* 
*/

#define BIND_AXIS(name, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);
#define BIND_ACTION(name, eventType, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAction(name, eventType, owner, method);

#define HORIZONTAL "Horizontal"
#define VERTICAL "Vertical"
#define PITCHROTATION "PitchRotation"
#define ROLLROTATION "RollRotation"
#define BLOW_UP "BlowUp"
#define SCALE "Scale"
#define RESPAWN "Respawn"
#define RESETROTATION "ResetRotation"
#define VIEW "View"