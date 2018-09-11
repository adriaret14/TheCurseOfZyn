// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RegisterHttp.generated.h"

USTRUCT()
struct FRequest_Register {
	GENERATED_BODY()
		UPROPERTY() FString username;
	UPROPERTY() FString password;
	UPROPERTY() FString email;
	UPROPERTY() FString name;
	UPROPERTY() FString surname;
	UPROPERTY() FString country;
	UPROPERTY() FString city;
	UPROPERTY() FString birthdate;

	FRequest_Register() {}
};

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
	void GetJsonStringFromStruct(FRequest_Register FilledStruct, FString& StringOutput);
	bool CheckInputs(FString username, FString password, FString cpassword, FString email, FString name, FString surname, FString Country, FString city, FString birthday);
	UFUNCTION(BluePrintCallable)
	void CheckUsername(FString username);
	UFUNCTION(BluePrintCallable)
	void CheckEmail(FString email);
	UFUNCTION(BluePrintCallable)
	void CheckPassword(FString password, FString cpassword);
	void OnResponesReceivedCU(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull);
	void OnResponesReceivedCE(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool value;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString error;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool flag;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool flagUsername;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool flagPassword;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool flagEmail;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
