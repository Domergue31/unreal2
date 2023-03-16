#pragma once

#include <Kismet/KismetMathLibrary.h>

#define LOG(log, msg, ...) UE_LOG(log, Display, TEXT(msg), __VA_ARGS__);
#define LOG_W(log, msg, ...) UE_LOG(log, Warning, TEXT(msg), __VA_ARGS__);
#define LOG_E(log, msg, ...) UE_LOG(log, Error, TEXT(msg), __VA_ARGS__);

#define LOG_SCREEN(time, color, msg) GEngine->AddOnScreenDebugMessage(-1, time, color, FString(msg));

/*DECLARE_LOG_CATEGORY_EXTERN(P1, Log, All)
DEFINE_LOG_CATEGORY(P1)

DECLARE_LOG_CATEGORY_EXTERN(CCC, Log, All)
DEFINE_LOG_CATEGORY(CCC)

DECLARE_LOG_CATEGORY_EXTERN(Thibaud, Log, All)
DEFINE_LOG_CATEGORY(Thibaud)*/

#define WORLD GetWorld()
#define PAWN WORLD->GetFirstPlayerController()->GetPawn()
#define DELTATIME WORLD->DeltaTimeSeconds

#define USE_DEBUG 1


#define DRAW_SPHERE_DEF(center, radius, seg, color, thick) DrawDebugSphere(WORLD, center, radius, seg, color, false, -1.0f, 0, thick);
#define DRAW_SPHERE(center, radius, color, thick)\
    if (USE_DEBUG) DrawDebugSphere(WORLD, center, radius, 20, color, false, -1.0f, 0, thick);
#define DRAW_BOX(center, seg, color, thick)\
    if (USE_DEBUG) DrawDebugBox(WORLD, center, seg, color, false, -1.0f, 0, thick);
#define DRAW_LINE(start, end, color, thick)\
    if (USE_DEBUG) DrawDebugLine(WORLD, start, end, color, false, -1.0f, 0, thick);
#define DRAW_TEXT(loc, text, color, size)\
    if (USE_DEBUG) DrawDebugString(WORLD, loc, text, nullptr, color,DELTATIME, false, size);

#define LERP_COLOR(from, to, t) UKismetMathLibrary::LinearColorLerp(from, to, t).ToFColor(true);

#define TO_CHAR(string) *string
#define TO_STRING(notString) notString.ToString()
#define TO_CHAR_STR(text) TO_CHAR(TO_STRING(text))

typedef FColor C;
typedef FVector Vec;


#define ATTACH_TO(from, to) from->SetupAttachment(to);
