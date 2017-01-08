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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ModifyLives(int Value);

	void BrickDestroyed();

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Game State")
	int32 CurrentScore;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "UI")
	FVector2D ConstrainAspectRatioOffset;

	UFUNCTION(BlueprintImplementableEvent, Category = "Blueprint Events")
	void OnNewLevel(int32 LevelIndex);

protected:

	virtual void InitGameState();

	void NextLevel();
	void RestartGame();

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true"))
	int32 CurrentLives;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true"))
	int32 CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blueprints")
	UClass* LevelBuilderBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blueprints")
	UClass* BallBP;
	
	class ALevelBuilder* LevelBuilder;
	class ABall* Ball;
};
