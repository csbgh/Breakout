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

	// normalized movement direction of the ball
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MoveDirection;

	// speed at which the ball moves in the movement direction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed;

	// What physics objects the ball will hit
	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Movement")
	FName MovementCollisionProfile;

private:

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* BallSprite;
	
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Ball", meta = (AllowPrivateAccess = "true"))
	float CollisionRadius;

};
