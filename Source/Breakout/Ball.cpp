// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "PaperSpriteComponent.h"
#include "BallMovementComponent.h"
#include "BreakoutGameState.h"
#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BallSprite"));
	BallSprite->SetSimulatePhysics(false);
	BallSprite->SetEnableGravity(false);
	BallSprite->BodyInstance.bLockRotation = true;
	BallSprite->SetCollisionProfileName(FName("Ball"));

	if (RootComponent == nullptr)
	{
		RootComponent = BallSprite;
	}

	Movement = CreateDefaultSubobject<UBallMovementComponent>(TEXT("Movement"));
	Movement->OnProjectileBounce.AddDynamic(this, &ABall::OnProjectileBounce);

	// Add event for when actor overlaps triggers
	BallSprite->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlap);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	ResetBall(0.1f);
}

// Called every frame
void ABall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ABall::OnOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (UWorld* CurWorld = GetWorld())
	{
		AGameStateBase* GameState = CurWorld->GetGameState();
		if (GameState != nullptr)
		{
			ABreakoutGameState* BreakoutGameState = (ABreakoutGameState*)GameState;
			BreakoutGameState->CurrentLives -= 1;
		}
	}
	ResetBall(1.5f);
}

void ABall::OnProjectileBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity)
{
	OnBallBounce(FVector(0, 0, 0), FVector(0, 0, 0));
}

void ABall::OnBallRelease()
{
	Movement->Velocity = FVector(1.0f, 0.0f, 1.0f) * Movement->InitialSpeed;
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}

void ABall::ResetBall(float ReleaseDelayTime)
{
	Movement->Velocity = FVector(0, 0, 0);
	if (UWorld* World = GetWorld())
	{
		APlayerController* Player = World->GetFirstPlayerController();
		AttachToActor(Player->GetPawn(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("BallSpawn"));

		FTimerHandle ReleaseTimer;
		GetWorldTimerManager().SetTimer(ReleaseTimer, this, &ABall::OnBallRelease, ReleaseDelayTime, false);
	}
}

