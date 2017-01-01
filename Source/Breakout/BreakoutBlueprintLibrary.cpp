// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "BreakoutBlueprintLibrary.h"

#include "Runtime/Engine/Classes/Engine/UserInterfaceSettings.h"
#include "Runtime/Engine/Classes/Engine/RendererSettings.h"

float UBreakoutBlueprintLibrary::GetCurrentDPIScale()
{
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	const float DPIScale = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass())->GetDPIScaleBasedOnSize(FIntPoint(ViewportSize.X, ViewportSize.Y));
	return DPIScale;
}



