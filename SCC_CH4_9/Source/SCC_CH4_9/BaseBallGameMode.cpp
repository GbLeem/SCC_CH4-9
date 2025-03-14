// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBallGameMode.h"

//make random number without same number
int32 ABaseBallGameMode::MakeRandomNumber()
{
	TSet<int32> UniqueNumber;
	int32 mult = 1;
	int32 idx = 2;

	while (UniqueNumber.Num() < 3)
	{
		int32 RandomNumber = FMath::RandRange(1, 9);
		UniqueNumber.Add(RandomNumber);
	}

	for (int32& Num : UniqueNumber)
	{
		Result += Num * mult;
		ResultArray.Add({ Num, idx });
		mult *= 10;
		idx--;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("%d"), Result));

	return Result;
}

FString ABaseBallGameMode::GetResult(FString Message)
{
	int32 Res = FCString::Atoi(*Message);
	
	TArray<int32> Temp; //input value

	int32 Strike = 0;
	int32 Ball = 0;

	Temp.Add(Res / 100);
	Res -= (Res / 100) * 100;
	Temp.Add(Res / 10);
	Res -= (Res / 10) * 10;
	Temp.Add(Res);

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("%d %d %d"), Temp[0], Temp[1], Temp[2]));

	for (int i = 0; i < Temp.Num(); ++i)
	{
		//if find
		if (ResultArray.Find(Temp[i]))
		{
			if (ResultArray[Temp[i]] == i)
				Strike++;
			else
				Ball++;
		}
	}

	if (Strike == 3)
		return FString(TEXT("CLEAR"));

	return FString::Printf(TEXT("%d S %d B"), Strike, Ball);
}