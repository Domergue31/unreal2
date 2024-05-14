// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Components/BoxComponent.h"
#include "OnlineManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class INTRONETWORK_API UOnlineManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess)) FName sessionName = "O3D-Session-Thibaud";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess)) FName serverName = "O3DProg";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess)) FString ipAddress = "0.0.0.0";

#pragma region net ptr
	IOnlineSubsystem* online = nullptr;
	IOnlineSessionPtr session;
	TSharedPtr<FOnlineSessionSearch> sessionSearch;
#pragma endregion net ptr
	TObjectPtr<UBoxComponent> box = nullptr;
private:
	UOnlineManagerSubsystem();
	void InitOnline();
	void Initialize(FSubsystemCollectionBase& _collection) override;
	void Deinitialize() override;

public:
	UFUNCTION(BlueprintCallable) void CreateServer();
	UFUNCTION(BlueprintCallable) void FindServer();

private:
//EVENTS
	void OnCreateSessionComplete(FName _sessionName, bool _success);
	void OnFindSessionCompleted(bool _success);
	void OnJoinSessionCompleted(FName _sessionName, EOnJoinSessionCompleteResult::Type _result);
};
