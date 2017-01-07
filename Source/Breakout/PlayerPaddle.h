// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerPaddle.generated.h"

UCLASS()
class BREAKOUT_API APlayerPaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPaddle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:

	void Move(float AxisValue);

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Paddle", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* PaddleSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Paddle", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	FVector CollisionBoxHalfExtents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	FName CollisionProfile;

};
