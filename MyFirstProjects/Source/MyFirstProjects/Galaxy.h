
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetCorrection.h"
#include "Galaxy.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API AGalaxy : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TArray<APlanetCorrection*> allPlanets;
	
	UPROPERTY()
		TObjectPtr<class ASpaceCraftCorrection> currentShip = nullptr;
public:	
	AGalaxy();
	void InitGalaxy(ASpaceCraftCorrection* _ship);
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawDebugGalaxy();
	void UpdatePlanetSize(ASpaceCraftCorrection* _ship);
};
