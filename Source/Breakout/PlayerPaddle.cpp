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

	MoveSpeed = 100.0f;

	PaddleSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaddleSprite"));
	RootComponent = PaddleSprite;
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
		FVector CurPos = GetActorLocation();
		FVector MovementDirection = FVector(PaddleInput.MovementX * MoveSpeed, 0.0f, 0.0f) * DeltaTime;
		FVector DesiredPos = CurPos + MovementDirection;

		if (UWorld* World = GetWorld())
		{
			FHitResult OutHit;
			FCollisionShape CollisionShape;
			CollisionShape.SetBox(CollisionBoxHalfExtents);

			if (World->SweepSingleByProfile(OutHit, CurPos, DesiredPos, FQuat::MakeFromEuler(FVector(-90.0f, 0.0f, 0.0f)), CollisionProfile, CollisionShape))
			{
				SetActorLocation(OutHit.Location + (OutHit.Normal * 0.1f));
			}
			else
			{
				SetActorLocation(DesiredPos);
			}
		}
	}
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis(TEXT("PaddleMovement"), this, &APlayerPaddle::Move);
}

void APlayerPaddle::Move(float AxisValue)
{
	PaddleInput.Move(AxisValue);
}
