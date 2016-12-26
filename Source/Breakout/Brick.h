// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class BREAKOUT_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Brick", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* BrickSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brick", meta = (AllowPrivateAccess = "true"))
	int32 MaxHealth;
};

/*UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EBrickType : uint8
{
Blue 	UMETA(DisplayName = "Red"),
Green	UMETA(DisplayName = "Blue"),
Red		UMETA(DisplayName = "Song"),
Purple	UMETA(DisplayName = "Purple"),
Yellow	UMETA(DisplayName = "Yellow"),
Black	UMETA(DisplayName = "Black"),
White	UMETA(DisplayName = "White")
};*/