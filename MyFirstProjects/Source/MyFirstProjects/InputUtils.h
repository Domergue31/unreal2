// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*
* 
*/

#define BIND_AXIS(name, owner, method) WORLD->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);

#define HORIZONTAL "Horizontal"
#define VERTICAL "Vertical"
#define ROTATION "Rotation"
#define BLOW_UP "BlowUp"