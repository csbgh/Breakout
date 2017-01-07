// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "BallMovementComponent.h"

UBallMovementComponent::UBallMovementComponent()
{
	MinBounceAngle = 10.0f;
	MaxBounceAngle = 55.0f;
	MinBounceSpeed = 75.0f;
	MaxBounceSpeed = 200.0f;
	ProjectileGravityScale = 0.0f;
	InitialSpeed = 75.0f;
	MaxSpeed = 200.0f;
	Velocity = FVector(1, 0, 1);
	bShouldBounce = true;
}

FVector UBallMovementComponent::ComputeBounceResult(const FHitResult& Hit, float TimeSlice, const FVector& MoveDelta)
{
	FVector NewVelocity = FVector(1, 0, 1);
	AActor* HitActor = Hit.GetActor();
	AActor* Owner = GetOwner();

	if (HitActor != nullptr && Owner != nullptr && HitActor->ActorHasTag(FName("Paddle")))
	{
		FVector PaddlePosition = HitActor->GetActorLocation();
		FVector BallPosition = Owner->GetActorLocation();

		FVector Origin, Extents;
		HitActor->GetActorBounds(true, Origin, Extents);

		// The distance from the center of the paddle, normalized to its size
		float HitDistance = (BallPosition.X - PaddlePosition.X) / Extents.X;

		// Determine the angle the ball will bounce at
		float BounceAngle = FMath::DegreesToRadians(FMath::Lerp(MinBounceAngle, MaxBounceAngle, FMath::Abs(HitDistance)));
		BounceAngle = HitDistance > 0.0f ? BounceAngle : -BounceAngle;

		// Get and apply the new direction of the balls movement
		// Multiply by the paddle direction to flip the direction for the right paddle
		float Speed = FMath::Lerp(MinBounceSpeed, MaxBounceSpeed, FMath::Abs(HitDistance));
		FVector NewDirection = FVector::ZeroVector;
		NewDirection.X = FMath::Sin(BounceAngle);
		NewDirection.Z = FMath::Cos(BounceAngle);
		NewVelocity = NewDirection * Speed;
	}
	else
	{
		NewVelocity = FMath::GetReflectionVector(Velocity, Hit.Normal);
	}

	return NewVelocity;
}




