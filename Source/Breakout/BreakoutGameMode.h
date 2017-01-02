// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "BreakoutGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakoutGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Paddle")
	int32 CurrentScore;
	
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "UI")
	FVector2D ConstrainAspectRatioOffset;
};
