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

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Game State")
	int32 CurrentLives;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "UI")
	FVector2D ConstrainAspectRatioOffset;

protected:

	virtual void InitGameState();

private:

	void RestartGame();
	
};
