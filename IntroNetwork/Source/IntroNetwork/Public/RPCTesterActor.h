// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "RPCTesterActor.generated.h"

/**
 * 
 */
UCLASS()
class INTRONETWORK_API ARPCTesterActor : public AActor
{
	GENERATED_BODY()
	
public:
	ARPCTesterActor();
private:
	//UFUNCTION(Client, UnReliable, BlueprintCallable) void ClientRPC_Test();
	UFUNCTION(Client, Reliable, BlueprintCallable) void ClientRPC_Test();
	UFUNCTION(Server, Reliable, BlueprintCallable) void ServerRPC_Test();
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable) void MulticastRPC_Test();
};
