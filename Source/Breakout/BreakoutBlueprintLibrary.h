// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BreakoutBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BREAKOUT_API UBreakoutBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "User Interface")
	static float GetCurrentDPIScale();
	
};
