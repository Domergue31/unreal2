// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineManagerSubsystem.h"
#include "OnlineSessionSettings.h"
#include <Online/OnlineSessionNames.h>
#include <OnlineSubsystemSteam.h>
#include <OnlineSubsystemUtils.h>
#include <OnlineSubsystemTypes.h>
#include <Interfaces/OnlinePresenceInterface.h>
#include "Kismet/KismetSystemLibrary.h"

#define IS_LAN() IOnlineSubsystem::Get()->GetSubsystemName() == "NULL"



UOnlineManagerSubsystem::UOnlineManagerSubsystem()
{
	
}


void UOnlineManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	InitOnline();
}

void UOnlineManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UOnlineManagerSubsystem::InitOnline()
{
	online = IOnlineSubsystem::Get();
	if (online)
	{
		UKismetSystemLibrary::PrintString(this, IOnlineSubsystem::Get()->GetSubsystemName().ToString(), true, true, FLinearColor::Blue);
		session = online->GetSessionInterface();
		if (session)
		{
			session->OnCreateSessionCompleteDelegates.AddUObject(this, &UOnlineManagerSubsystem::OnCreateSessionComplete);
			session->OnFindSessionsCompleteDelegates.AddUObject(this, &UOnlineManagerSubsystem::OnFindSessionComplete);
			session->OnJoinSessionCompleteDelegates.AddUObject(this, &UOnlineManagerSubsystem::OnJoinSessionComplete);
		}
	}

}

void UOnlineManagerSubsystem::OnCreateSessionComplete(FName _sessionName, bool _success)
{
	UKismetSystemLibrary::PrintString(this, "Session " + sessionName.ToString(), true, true, FLinearColor::Blue);
	if (_success)
	{
		UKismetSystemLibrary::PrintString(this, "Session " + sessionName.ToString(), true, true, FLinearColor::Blue);
		const FString _path = "ThirdPersonMap?listen";
		session->GetResolvedConnectString(sessionName, ipAddress);
		GetWorld()->ServerTravel(_path, true);
	}
}

void UOnlineManagerSubsystem::OnFindSessionComplete(bool _success)
{
	if (_success)
	{
		TArray<FOnlineSessionSearchResult> _res = sessionSearch->SearchResults;
		UKismetSystemLibrary::PrintString(this, "Session Found -> " + FString::FromInt(_res.Num()), true, true, FLinearColor::Blue);
		for (FOnlineSessionSearchResult _r : _res)
		{
			FString _name = "";
			_r.Session.SessionSettings.Get(FName("SERVER_NAME"), _name);
			if (_name.Equals(serverName.ToString()))
			{
				UKismetSystemLibrary::PrintString(this, "Found Server => " + _name, true, true, FLinearColor::Green);
				session->JoinSession(0, sessionName, _r);
				return;
			}
		}
	}
}

void UOnlineManagerSubsystem::OnJoinSessionComplete(FName _sessionName, EOnJoinSessionCompleteResult::Type _result)
{
	if (_result == EOnJoinSessionCompleteResult::Success)
	{
		UKismetSystemLibrary::PrintString(this, "Join " + serverName.ToString(), true, true, FLinearColor::Blue);
		session->GetResolvedConnectString(sessionName, ipAddress);
		UKismetSystemLibrary::PrintString(this, "IP =>" + ipAddress, true, true, FLinearColor::Blue);
		APlayerController* _pc = GetGameInstance()->GetFirstLocalPlayerController();
		if (_pc)
		{
			_pc->ClientTravel(ipAddress, ETravelType::TRAVEL_Absolute);
		}
	}
}


void UOnlineManagerSubsystem::CreateServer()
{
	UKismetSystemLibrary::PrintString(this, "Create Server " + serverName.ToString(), true, true, FLinearColor::Blue);
	if (session->GetNamedSession(sessionName))
	{
		session->DestroySession(sessionName);
		return;
	}

	FOnlineSessionSettings _sessionSettings;
	_sessionSettings.bAllowJoinInProgress = true;
	_sessionSettings.bIsDedicated = true;	//server dedicated
	_sessionSettings.bShouldAdvertise = true; //public
	_sessionSettings.NumPublicConnections = 20;
	_sessionSettings.bUsesPresence = true;	//
	_sessionSettings.bAllowJoinViaPresence = true;
	_sessionSettings.bUseLobbiesIfAvailable = true;
	_sessionSettings.bIsLANMatch = IS_LAN();
	_sessionSettings.Set(FName("SERVER_NAME"), serverName.ToString(), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing); //#sensible
	session->CreateSession(0, sessionName, _sessionSettings); //#sensible
}

void UOnlineManagerSubsystem::FindServer()
{
	UKismetSystemLibrary::PrintString(this, "Find Server... ", true, true, FLinearColor::Yellow);
	sessionSearch = MakeShareable(new FOnlineSessionSearch());
	sessionSearch->bIsLanQuery = IS_LAN();
	sessionSearch->MaxSearchResults = 999;
	sessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
	session->FindSessions(0, sessionSearch.ToSharedRef());
}