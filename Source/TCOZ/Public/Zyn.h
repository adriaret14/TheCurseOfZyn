// Fill out your copyright notice in the Description page of Project Settings.
#include "CharacterStats.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Zyn.generated.h"

UCLASS()
class TCOZ_API AZyn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZyn();

	UPROPERTY(EditAnywhere, Category="AAAAAAAAA")
		UCharacterStats* stats;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
