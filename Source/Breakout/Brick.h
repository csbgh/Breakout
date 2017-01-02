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

	UFUNCTION(BlueprintImplementableEvent, Category = "Brick")
	void OnBrickDestroyed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Brick")
	void OnBrickHit();

protected:

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit);

private:

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Brick", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* BrickSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brick", meta = (AllowPrivateAccess = "true"))
	int32 MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brick", meta = (AllowPrivateAccess = "true"))
	int32 ScoreValue;
};