// Fill out your copyright notice in the Description page of Project Settings.


#include "RPCTesterActor.h"
#include "Utils/DevUtils.h"


ARPCTesterActor::ARPCTesterActor()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void ARPCTesterActor::ClientRPC_Test_Implementation()
{
	LOG_C_T("Client RPC", Green, 10);
}

void ARPCTesterActor::ServerRPC_Test_Implementation()
{
	LOG_C_T("Server RPC", Red, 10);
}

void ARPCTesterActor::MulticastRPC_Test_Implementation()
{
	LOG_C_T("Multicast RPC", Blue, 10);
}
