// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseBallGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SCC_CH4_9_API ABaseBallGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	int32 MakeRandomNumber();

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	FString GetResult(FString Message);

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	bool ValidCheck(FString Message);

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	void ResetTurnAndCount();

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	int32 CheckTurnAndID(FString Message);

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	bool WinCheck(FString Message);

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	void StartTimer();

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	void ClearTimer();

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	void EndTimer();

	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	void GetRemainTime();

	UFUNCTION(BlueprintImplementableEvent, Category = "MyEvents")
	void ResetValues();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseballGame")
	int32 Result = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseballGame")
	TMap<int32, int32> ResultArray;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	int32 TurnIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	int32 HostCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	int32 GuestCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	int32 HostWinCount = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	int32 GuestWinCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	FTimerHandle Timer;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseballGame")
	float RemainingTime = 10.f;
};
