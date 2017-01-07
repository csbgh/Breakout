// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameStateBase.h"
#include "BreakoutGameState.generated.h"

/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakoutGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	ABreakoutGameState();

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Game State")
	int32 CurrentScore;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "UI")
	FVector2D ConstrainAspectRatioOffset;

	void ModifyLives(int Value);

protected:

	virtual void InitGameState();

	void RestartGame();

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Game State")
	int32 CurrentLives;
	
};
