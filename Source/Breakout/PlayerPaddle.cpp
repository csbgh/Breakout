// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "PaperSpriteComponent.h"
#include "PlayerPaddle.h"

void FPaddleInput::Sanitize()
{
	MovementX = FMath::Clamp(RawMovementInput, -1.0f, 1.0f);
	RawMovementInput = 0.0f;
}

void FPaddleInput::Move(float AxisValue)
{
	RawMovementInput += AxisValue;
}

// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (RootComponent == nullptr)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PaddleBase"));
	}

	PaddleSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaddleSprite"));
	PaddleSprite->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPaddle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	PaddleInput.Sanitize();

	// Move Paddle
	{
		FVector MovementDirection = FVector(PaddleInput.MovementX * 100.0f, 0.0f, 0.0f) * DeltaTime;
		FVector Pos = GetActorLocation();
		SetActorLocation(Pos + MovementDirection);
	}
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis(TEXT("PaddleMovement"), this, &APlayerPaddle::Move);
}

void APlayerPaddle::Move(float AxisValue)
{
	PaddleInput.Move(AxisValue);
}
