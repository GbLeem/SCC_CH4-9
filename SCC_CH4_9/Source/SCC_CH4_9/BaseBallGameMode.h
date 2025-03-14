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

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseballGame")
	int32 Result = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseballGame")
	TMap<int32, int32> ResultArray;
};
