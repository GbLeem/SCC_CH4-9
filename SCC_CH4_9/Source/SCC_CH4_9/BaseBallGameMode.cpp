// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBallGameMode.h"

//make random number without same number
int32 ABaseBallGameMode::MakeRandomNumber()
{
	TSet<int32> UniqueNumber;
	int32 mult = 1;
	int32 idx = 2;
	Result = 0;

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

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::Printf(TEXT("%d"), Result));

	return Result;
}

FString ABaseBallGameMode::GetResult(FString Message)
{
	//false
	if (!ValidCheck(Message))
		return FString(TEXT("OUT"));

	int32 Res = FCString::Atoi(*Message);
	
	TArray<int32> Temp; //input value

	int32 Strike = 0;
	int32 Ball = 0;

	Temp.Add(Res / 100);
	Res -= (Res / 100) * 100;
	Temp.Add(Res / 10);
	Res -= (Res / 10) * 10;
	Temp.Add(Res);

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
	{
		return FString("CLEAR");
	}

	return FString::Printf(TEXT("%d S %d B"), Strike, Ball);
}

bool ABaseBallGameMode::ValidCheck(FString Message)
{
	//3자리가 아님
	if (Message.Len() != 3)
		return false;
	
	//중복된 숫자가 있는 경우
	TSet<TCHAR> MessageSet;

	for (TCHAR Char : Message)
	{
		if (MessageSet.Contains(Char))
			return false;

		MessageSet.Add(Char);
	}

	return true;
}

void ABaseBallGameMode::ResetTurnAndCount()
{
	TurnIndex = 1;
	HostCount = 3;
	GuestCount = 3;
}

int32 ABaseBallGameMode::CheckTurnAndID(FString Message)
{
	//odd number and "HOST"
	if (TurnIndex % 2 != 0 && Message.Equals(TEXT("HOST")))
	{
		TurnIndex++;
		HostCount--;

		return 1;
	}

	//even number and "GUEST"
	if (TurnIndex % 2 == 0 && Message.Equals(TEXT("GUEST")))
	{
		TurnIndex++;
		GuestCount--;

		return 2;
	}

	return 3;
}

bool ABaseBallGameMode::WinCheck(FString Message)
{
	if (Message.Equals(TEXT("CLEAR")))	
		return true;	
	else
		return false;
}

void ABaseBallGameMode::StartTimer()
{
	GetWorldTimerManager().SetTimer(Timer, this, &ABaseBallGameMode::EndTimer, 10.f, false);
}

void ABaseBallGameMode::ClearTimer()
{
	GetWorldTimerManager().ClearTimer(Timer);
	StartTimer();
}

void ABaseBallGameMode::EndTimer()
{
	TurnIndex++;
	ClearTimer();
	StartTimer();
	ResetValues();
}

void ABaseBallGameMode::GetRemainTime()
{
	RemainingTime = GetWorldTimerManager().GetTimerRemaining(Timer);
}