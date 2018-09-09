// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TCOZ_API UCharacterStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStats();

	UPROPERTY(EditAnywhere, Category="Defense")
		float MaxHealth;
	UPROPERTY(EditAnywhere, Category = "Defense")
		float CurrentHealth;
	UPROPERTY(EditAnywhere, Category = "Defense")
		float HealthRegen;
	UPROPERTY(EditAnywhere, Category = "Offense")
		float AttackDamage;
	UPROPERTY(EditAnywhere, Category = "Offense")
		float AttackSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed;
	UPROPERTY(EditAnywhere, Category = "Other")
		float MagicFind;
	UPROPERTY(EditAnywhere, Category = "Defense")
		float Armor;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
