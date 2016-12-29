// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "PaperSpriteComponent.h"
#include "Ball.h"

// #include "DrawDebugHelpers.h"
// DrawDebugLine(World, CurPos, CurPos + (MoveDirection * 100.0f), FColor::Red, false, 0.1f, 0, 2.0f);

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (RootComponent == nullptr)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BallBase"));
	}

	BallSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BallSprite"));
	BallSprite->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector CurPos = GetActorLocation();
	FVector DesiredPos = CurPos + ((MoveDirection * MoveSpeed) * DeltaTime);

	if (UWorld* World = GetWorld())
	{
		FHitResult OutHit;
		FCollisionShape CollisionShape;
		CollisionShape.SetCapsule(CollisionRadius, 128.0f);

		if (World->SweepSingleByProfile(OutHit, CurPos, DesiredPos, FQuat::MakeFromEuler(FVector(-90.0f, 0.0f, 0.0f)), MovementCollisionProfile, CollisionShape))
		{
			SetActorLocation(CurPos);
			MoveDirection = -MoveDirection; // Simple temporary bounce..
		}
		else
		{
			SetActorLocation(DesiredPos);
		}
	}
}

