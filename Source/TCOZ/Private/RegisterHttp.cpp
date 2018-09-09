// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterHttp.h"


// Sets default values
ARegisterHttp::ARegisterHttp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARegisterHttp::RegistrarUsuario(FString username, FString password, FString cpassword, FString email, FString name, FString surname, FString country, FString city, FString birthdate)
{
	http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ARegisterHttp::OnResponesReceived);
	Request->SetURL("http://thecurseofzyn.x10host.com/GAME/prueba.php");
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
}

void ARegisterHttp::OnResponesReceived(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(response->GetContentAsString());
	if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
		 int32 recievedInt = JsonObject->GetIntegerField("customInt");
		 //GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
		 if (recievedInt == 1)
		 {
			 value = true;
		}
		 else
		 {
			 value = false;
			 error="You may not have Internet Connection"
			 }
		 }
	}
}




// Called when the game starts or when spawned
void ARegisterHttp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARegisterHttp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

