#pragma once

#include "Kismet/KismetSystemLibrary.h"


#define LOG(msg) UKismetSystemLibrary::PrintString(this, msg)
#define LOG_C(msg, color) UKismetSystemLibrary::PrintString(this, msg, true, true, FLinearColor::color)
#define LOG_C_T(msg, color, time) UKismetSystemLibrary::PrintString(this, msg, true, true, FLinearColor::color, time)