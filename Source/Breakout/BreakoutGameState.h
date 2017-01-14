// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameStateBase.h"
#include "BreakoutGameState.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	VE_Playing 		UMETA(DisplayName = "Playing"),
	VE_GameOver 	UMETA(DisplayName = "Game Over")
};

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

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Game State")
	EGameState GameState;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "UI")
	FVector2D ConstrainAspectRatioOffset;

	UFUNCTION(BlueprintImplementableEvent, Category = "Blueprint Events")
	void OnNewLevel(int32 LevelIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = "Blueprint Events")
	void OnLifeLost();

protected:

	virtual void InitGameState();

	void NextLevel();
	void RestartGame();
	void GameOver();

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true"))
	int32 CurrentLives;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true"))
	int32 CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blueprints")
	UClass* LevelBuilderBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blueprints")
	UClass* BallBP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> GameOverWidgetTemplate;

	UPROPERTY()
	UUserWidget* GameOverWidgetInstance;
	
	class ALevelBuilder* LevelBuilder;
	class ABall* Ball;
};
