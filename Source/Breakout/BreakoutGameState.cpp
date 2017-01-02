// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "BreakoutGameState.h"


ABreakoutGameState::ABreakoutGameState()
{
	CurrentScore = 0;
	CurrentLives = 3;
}

void ABreakoutGameState::InitGameState()
{

}

void ABreakoutGameState::RestartGame()
{
	CurrentScore = 0;
	CurrentLives = 3;
}

