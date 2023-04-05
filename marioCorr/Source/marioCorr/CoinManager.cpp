// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinManager.h"

void UCoinManager::ResetCoins()
{
	coins = 0;
	onAddCoin.Broadcast(coins);
}
