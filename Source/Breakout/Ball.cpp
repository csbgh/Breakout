// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "PaperSpriteComponent.h"
#include "BallMovementComponent.h"
#include "Ball.h"

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
	BallSprite->SetSimulatePhysics(true);
	BallSprite->SetEnableGravity(false);
	BallSprite->BodyInstance.bLockRotation = true;
	BallSprite->SetCollisionProfileName(FName("Ball"));

	Movement = CreateDefaultSubobject<UBallMovementComponent>(TEXT("Movement"));
	Movement->SetUpdatedComponent(BallSprite);
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
}

