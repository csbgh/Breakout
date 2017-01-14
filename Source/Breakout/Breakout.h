// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

UENUM(BlueprintType)
enum class EUIButtonAction : uint8
{
	VE_NewGame 		UMETA(DisplayName = "New Game"),
	VE_GoToMenu 	UMETA(DisplayName = "Go To Menu"),
	VE_Options		UMETA(DisplayName = "Open Options"),
	VE_Credits		UMETA(DisplayName = "Open Credits"),
	VE_Back			UMETA(DisplayName = "Menu Back")
};

