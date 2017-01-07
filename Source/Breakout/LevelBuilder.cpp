// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "LevelBuilder.h"
#include <Runtime/Core/Public/Misc/Char.h>
#include "Brick.h"

// Sets default values
ALevelBuilder::ALevelBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelBuilder::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALevelBuilder::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ALevelBuilder::SpawnLevel(int32 LevelIndex)
{
	// ensure level index is valid
	if (LevelIndex >= Levels.Num()) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not spawn level 'LevelIndex' out of bounds of available levels."));
		return;
	}

	// remove any existing bricks
	for (TActorIterator<ABrick> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ActorItr->Destroy();
	}

	// parse level data
	FString LevelData = Levels[LevelIndex];
	TArray<FLevelRow> Rows;

	FLevelRow CurrentRow;
	FString CurValue = "";
	for (int32 c = 0; c < LevelData.Len(); c++)
	{
		// ignore spaces
		if (LevelData[c] == ' ')
			continue;

		if (TChar<TCHAR>::IsDigit(LevelData[c]))
		{
			CurValue += LevelData[c];
		}
		
		if (LevelData[c] == ',' || LevelData[c] == '\n' || c == LevelData.Len() - 1)
		{
			// before converting to int check that the string has only numeric characters
			if (CurValue.IsNumeric())
			{
				CurrentRow.RowBricks.Add(FCString::Atoi(*CurValue));
			}
			CurValue = "";
		}

		if (LevelData[c] == '\n' || c == LevelData.Len()-1)
		{
			Rows.Add(CurrentRow);
			CurrentRow = FLevelRow();
			continue;
		}
	}

	float BrickWidth = 15.0f * 0.5f;
	float BrickHeight = 6.0f * 0.5f;

	FVector Origin = GetActorLocation();
	FVector RowStart = FVector(0.0f, -(static_cast<float>(Rows.Num()) * BrickHeight) - BrickHeight, 0.0f);
	FVector CurPosition = Origin;
	for (auto RowIt = Rows.CreateConstIterator(); RowIt; ++RowIt)
	{
		CurPosition.X = -((static_cast<float>(RowIt->RowBricks.Num())) * BrickWidth) + BrickWidth;
		for (auto ColIt = RowIt->RowBricks.CreateConstIterator(); ColIt; ++ColIt)
		{
			if (*ColIt != 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("CELL %i"), *ColIt);
				if (UWorld* World = GetWorld())
				{
					FActorSpawnParameters SpawnParams;
					World->SpawnActor<ABrick>(BrickActors[*ColIt-1], CurPosition, FRotator::ZeroRotator, SpawnParams);
				}
			}
			CurPosition.X += BrickWidth*2.0f;
		}
		CurPosition.Z -= BrickHeight*2.0f;
		UE_LOG(LogTemp, Warning, TEXT(","));
	}
}

