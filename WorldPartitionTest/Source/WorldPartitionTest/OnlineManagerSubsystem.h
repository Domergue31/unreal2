// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/OnlineFriendsInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemSteam.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemTypes.h"
#include "OnlineManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class WORLDPARTITIONTEST_API UOnlineManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	FName sessionName = "O3D-Session";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	FName serverName = "O3DProg";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	FString ipAddress = "0.0.0.0";


#pragma region Net_Variable
	IOnlineSubsystem* online = nullptr;
	IOnlineSessionPtr session;
	TSharedPtr<FOnlineSessionSearch> sessionSearch;
#pragma endregion

private:
	UOnlineManagerSubsystem();
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	void InitOnline();

	void OnCreateSessionComplete(FName _sessionName, bool _success);
	void OnFindSessionComplete(bool _success);
	void OnJoinSessionComplete(FName _sessionName, EOnJoinSessionCompleteResult::Type _result);

public:
	UFUNCTION(BlueprintCallable) void CreateServer();
	UFUNCTION(BlueprintCallable) void FindServer();
};
