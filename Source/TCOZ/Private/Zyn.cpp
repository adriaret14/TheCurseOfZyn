// Fill out your copyright notice in the Description page of Project Settings.

#include "Zyn.h"


// Sets default values
AZyn::AZyn()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	stats = CreateDefaultSubobject<UCharacterStats>(TEXT("Stats"));
	this->AddOwnedComponent(stats);

}

// Called when the game starts or when spawned
void AZyn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZyn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZyn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

