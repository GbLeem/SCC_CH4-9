// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestCPPLib.generated.h"

/**
 * 
 */
UCLASS()
class SCC_CH4_9_API UTestCPPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "CPPLib")
	static FString GetStringFromCPP();
};
