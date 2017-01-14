// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "BreakoutGameState.h"
#include "Brick.h"
#include "LevelBuilder.h"
#include "Ball.h"
#include "Blueprint/UserWidget.h"

ABreakoutGameState::ABreakoutGameState()
{
	CurrentScore = 0;
	CurrentLives = 3;
	CurrentLevel = 0;
}

void ABreakoutGameState::ModifyLives(int Value)
{
	CurrentLives += Value;

	if (Value < 0)
		OnLifeLost();

	if (CurrentLives <= 0)
		GameOver();
}

// Called when the game starts or when spawned
void ABreakoutGameState::BeginPlay()
{
	UWorld* World = GetWorld();

	// Create level builder object and spawn first level
	if (LevelBuilderBP != nullptr)
	{
		LevelBuilder = World->SpawnActor<ALevelBuilder>(LevelBuilderBP, FVector(0, 0, -25), FRotator::ZeroRotator);
		LevelBuilder->SpawnLevel(CurrentLevel);
	}

	// create ball
	if (BallBP != nullptr)
	{
		Ball = World->SpawnActor<ABall>(BallBP, FVector(0, 0, 0), FRotator::ZeroRotator);
		Ball->ResetBall(1.5f);
	}
}

void ABreakoutGameState::BrickDestroyed()
{
	// check if all bricks have been destroyed
	int32 BrickCount = 0;
	for (TActorIterator<ABrick> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		BrickCount++;
	}

	if (BrickCount <= 1)
	{
		NextLevel();
	}
}

void ABreakoutGameState::InitGameState()
{
}

void ABreakoutGameState::NextLevel()
{
	Ball->ResetBall(1.5f);

	CurrentLevel++;
	if (LevelBuilder != nullptr)
	{
		LevelBuilder->SpawnLevel(CurrentLevel);
		OnNewLevel(CurrentLevel);
	}
}

void ABreakoutGameState::RestartGame()
{
	CurrentScore = 0;
	CurrentLives = 3;
	CurrentLevel = 0;
	LevelBuilder->SpawnLevel(CurrentLevel);
	OnNewLevel(CurrentLevel);
}

void ABreakoutGameState::GameOver()
{
	GameState = EGameState::VE_GameOver;
	Ball->Destroy();

	APlayerController* PlayerController = nullptr;
	if (UWorld* World = GetWorld())
	{
		PlayerController = World->GetFirstPlayerController();
	}

	if (GameOverWidgetTemplate && PlayerController)
	{
		if (!GameOverWidgetInstance)
		{
			GameOverWidgetInstance = CreateWidget<UUserWidget>(PlayerController, GameOverWidgetTemplate);
		}
		
		if (!GameOverWidgetInstance->GetIsVisible())
		{
			GameOverWidgetInstance->AddToViewport();
		}
	}
}

