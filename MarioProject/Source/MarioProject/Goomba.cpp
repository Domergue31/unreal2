// Fill out your copyright notice in the Description page of Project Settings.


#include "Goomba.h"
#include "Projectiles.h"
#include "MarioProjectCharacter.h"
#include "Block.h"

// Sets default values
AGoomba::AGoomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoomba::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AGoomba::NotifyActorBeginOverlap(AActor* _other)
{
	AProjectiles* _spell = Cast<AProjectiles>(_other);
	if (_spell)
	{
		Hit();
		_spell->Destroy();
	}
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (_char)
		_char->Respawn();
	ABlock* _block = Cast<ABlock>(_other);
	if (_block)
		direction = -direction;
}

void AGoomba::Move()
{
	AddActorWorldOffset((GetActorForwardVector() * direction)  * GetWorld()->DeltaTimeSeconds * settings->Speed());
}

void AGoomba::Hit()
{
	actualLife--;
	if (actualLife == 0)
		Destroy();
}
