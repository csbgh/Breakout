// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/ProjectileMovementComponent.h"
#include "BallMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Movement, meta = (BlueprintSpawnableComponent), ShowCategories = (Velocity))
class BREAKOUT_API UBallMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()

public:

	UBallMovementComponent();

protected:

	virtual FVector ComputeBounceResult(const FHitResult& Hit, float TimeSlice, const FVector& MoveDelta) override;
	
private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PaddleBounce", meta = (AllowPrivateAccess = "true"))
	float MinBounceAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PaddleBounce", meta = (AllowPrivateAccess = "true"))
	float MaxBounceAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PaddleBounce", meta = (AllowPrivateAccess = "true"))
	float MinBounceSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PaddleBounce", meta = (AllowPrivateAccess = "true"))
	float MaxBounceSpeed;
};
