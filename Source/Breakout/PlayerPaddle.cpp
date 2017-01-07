// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "PaperSpriteComponent.h"
#include "PlayerPaddle.h"

// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 400.0f;

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

	// Move Paddle
	{
		bool MouseInWindow = true;

		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		FVector WorldPosition, WorldDirection;
		if (PlayerController != nullptr)
		{
			float LocationX, LocationY;
			PlayerController->GetMousePosition(LocationX, LocationY);
			FVector2D MousePosition(LocationX, LocationY);

			MouseInWindow = MousePosition.X > 0.0f && MousePosition.Y > 0.0f;

			PlayerController->DeprojectMousePositionToWorld(WorldPosition, WorldDirection);
		}

		if (MouseInWindow)
		{
			FVector CurPos = GetActorLocation();
			FVector DesiredPos = CurPos + FVector(WorldPosition.X - CurPos.X, 0, 0);

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
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void APlayerPaddle::Move(float AxisValue)
{
	
}
