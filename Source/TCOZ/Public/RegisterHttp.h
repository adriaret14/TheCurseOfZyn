// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RegisterHttp.generated.h"

UCLASS()
class TCOZ_API ARegisterHttp : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	ARegisterHttp();

	FHttpModule* http;

	UFUNCTION(BluePrintCallable)
		void RegistrarUsuario(FString username, FString password, FString cpassword, FString email, FString name, FString surname, FString country, FString city, FString birthdate);

	void OnResponesReceived(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull);
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool value;
	FString error;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
