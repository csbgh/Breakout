// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class BREAKOUT_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Ball")
	void OnBallBounce(const FVector& Position, const FVector& SurfaceNormal);

	UFUNCTION()
	void OnOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnProjectileBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity);

	UFUNCTION()
	void OnBallRelease();

	void ResetBall(float ReleaseDelayTime);

private:

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* BallSprite;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	class UBallMovementComponent* Movement;

};
