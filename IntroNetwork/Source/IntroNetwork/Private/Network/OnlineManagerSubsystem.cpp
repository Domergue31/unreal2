// Fill out your copyright notice in the Description page of Project Settings.


#include "Network/OnlineManagerSubsystem.h"
#include "Utils/DevUtils.h"
#include "ONlineSessionSettings.h"
#include <Online/OnlineSessionNames.h>
#include "OnlineSubsystemTypes.h"

#define IS_LAN() IOnlineSubsystem::Get()->GetSubsystemName().ToString() == "NULL";

UOnlineManagerSubsystem::UOnlineManagerSubsystem()
{
	sessionName = "O3D-Session-Thibaud";
}
void UOnlineManagerSubsystem::InitOnline()
{
	LOG_C("Enter online", Green);
	online = IOnlineSubsystem::Get();
	if (online)
	{
		LOG("ONLINE : " + online->GetSubsystemName().ToString());
		session = online->GetSessionInterface();
		if (session.IsValid())
		{
			session->OnCreateSessionCompleteDelegates.AddUObject(this, &UOnlineManagerSubsystem::OnCreateSessionComplete);
			session->OnFindSessionsCompleteDelegates.AddUObject(this, &UOnlineManagerSubsystem::OnFindSessionCompleted);
			session->OnJoinSessionCompleteDelegates.AddUObject(this, &UOnlineManagerSubsystem::OnJoinSessionCompleted);
		}
	}
}
void UOnlineManagerSubsystem::Initialize(FSubsystemCollectionBase& _collection)
{
	Super::Initialize(_collection);
	InitOnline();
}
void UOnlineManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	LOG_C("Exit online", Red);
}
void UOnlineManagerSubsystem::CreateServer()
{
	LOG_C("Server create " + serverName.ToString(), Green);
	if (serverName == "")
		return;
	
	if (session->GetNamedSession(sessionName))
	{
		session->DestroySession(sessionName);
		return;
	}
	FOnlineSessionSettings _sessionSettings;
	_sessionSettings.bAllowJoinInProgress = true;
	_sessionSettings.bShouldAdvertise = true;
	_sessionSettings.bAllowInvites = true;
	_sessionSettings.bIsDedicated = false;
	_sessionSettings.NumPublicConnections = 20;
	_sessionSettings.bUsesPresence = true;
	_sessionSettings.bAllowJoinViaPresence = true;
	_sessionSettings.bUseLobbiesIfAvailable = true;
	_sessionSettings.bIsLANMatch = IS_LAN();
	_sessionSettings.Set(FName("SERVER_NAME"), serverName.ToString(), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	session->CreateSession(0, sessionName, _sessionSettings);
}

void UOnlineManagerSubsystem::FindServer()
{
	if (serverName == "")
		return;
	LOG_C("Find server " + serverName.ToString(), Yellow);
	sessionSearch = MakeShareable(new FOnlineSessionSearch());
	sessionSearch->bIsLanQuery = IS_LAN();
	sessionSearch->MaxSearchResults = 999;
	sessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
	session->FindSessions(0, sessionSearch.ToSharedRef());
}

void UOnlineManagerSubsystem::OnCreateSessionComplete(FName _sessionName, bool _success)
{
	if (_success)
	{
		LOG_C("Session Created " + sessionName.ToString(), Green);
		const FString _path = "/Game/ThirdPerson/Maps/ThirdPersonMap?listen";
		session->GetResolvedConnectString(_sessionName, ipAddress);
		GetWorld()->ServerTravel(_path);
	}
	else
	{
		LOG_C("Session Failed " + sessionName.ToString(), Red);
	}
}

void UOnlineManagerSubsystem::OnFindSessionCompleted(bool _success)
{
	if (_success)
	{
		TArray<FOnlineSessionSearchResult> _results = sessionSearch->SearchResults;
		if (_results.Num() > 0)
		{
			LOG_C("SESSION FOUND -> " + FString::FromInt(_results.Num()), Green);
			for (FOnlineSessionSearchResult _r : _results)
			{
				if (_r.IsValid())
				{
					FString _name = "";
					_r.Session.SessionSettings.Get(FName("SERVER_NAME"), _name);
					LOG(_name);
					if (_name.Equals(serverName.ToString()))
					{
						LOG("FOUND SERVER");
						session->JoinSession(0, sessionName, _r);
						return;
					}
				}
			}
		}
		else
		{
			LOG_C("0 Session", Red);
		}
	}
}

void UOnlineManagerSubsystem::OnJoinSessionCompleted(FName _sessionName, EOnJoinSessionCompleteResult::Type _result)
{
	if (_result == EOnJoinSessionCompleteResult::Success)
	{
		LOG("JOIN -> " + _sessionName.ToString());
		session->GetResolvedConnectString(_sessionName, ipAddress);
		LOG("Ip : " + ipAddress);
		APlayerController* _pc = GetGameInstance()->GetFirstLocalPlayerController();
		if (_pc)
			_pc->ClientTravel(ipAddress, ETravelType::TRAVEL_Absolute);
	}
		
}
