// Fill out your copyright notice in the Description page of Project Settings.

#include "Breakout.h"
#include "PaperSpriteComponent.h"
#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (RootComponent == nullptr)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BrickBase"));
	}

	BrickSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BrickSprite"));
	BrickSprite->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrick::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

