// Fill out your copyright notice in the Description page of Project Settings.


#include "Galaxy.h"
#include "Utils.h"
#include "SpaceCraftCorrection.h"

// Sets default values
AGalaxy::AGalaxy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}


void AGalaxy::InitGalaxy(ASpaceCraftCorrection* _ship)
{	
	currentShip = _ship;
	for (APlanetCorrection* _planet : allPlanets)
	{
		if (!_planet)
			continue;
		_planet->SetInitDistance(_ship->GetActorLocation());
	}
}


// Called when the game starts or when spawned
void AGalaxy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGalaxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugGalaxy();
	UpdatePlanetSize(currentShip);
}

void AGalaxy::DrawDebugGalaxy()
{
	for (APlanetCorrection* _planet : allPlanets)
	{
		if (!_planet)
			continue;
		const FVector _ploc = _planet->GetActorLocation(),
			_shipLocation = currentShip->GetActorLocation();
		DRAW_BOX(_ploc, FVector(100), FColor::Green, 2);
		DRAW_LINE(_ploc, GetActorLocation(), FColor::Green, 2);
		DRAW_LINE(_ploc, _shipLocation, FColor::Red, 2);
		DRAW_TEXT(FMath::Lerp(_ploc, _shipLocation, .5f), FString::Printf(TEXT("%f/%f"), _planet->GetCurrentDistanceTo(_shipLocation), _planet->GetMaxDistance()),
			FColor::White, 1.2f);
	}
	DRAW_TEXT(GetActorLocation(), FString::Printf(TEXT("Galaxy center %s"), TO_CHAR_STR(GetActorLocation())), FColor::White, 1.2f);
	DRAW_BOX(GetActorLocation(), FVector(20), FColor::Yellow, 2);

}

void AGalaxy::UpdatePlanetSize(ASpaceCraftCorrection* _ship)
{
	if (!_ship)
		return;
	for (APlanetCorrection* _planet : allPlanets)
	{
		if (!_planet)
			continue;
		_planet->UpdateSize(_ship->GetActorLocation());
	}
}