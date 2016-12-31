// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "BallMovementComponent.h"

FVector UBallMovementComponent::ComputeBounceResult(const FHitResult& Hit, float TimeSlice, const FVector& MoveDelta)
{
	FVector NewVelocity = FMath::GetReflectionVector(Velocity, Hit.Normal);
	return NewVelocity;
}




