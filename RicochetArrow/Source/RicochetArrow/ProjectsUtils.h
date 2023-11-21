#pragma once

#include "CoreMinimal.h"


#define DELTATIME GetWorld()->DeltaTimeSeconds
#define LOG_ON_SCREEN(string) UKismetSystemLibrary::PrintString(this, string);