// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterHttp.h"
#include "Regex.h"

// Sets default values
ARegisterHttp::ARegisterHttp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARegisterHttp::RegistrarUsuario(FString username, FString password, FString cpassword, FString email, FString name, FString surname, FString country, FString city, FString birthdate)
{
	http = &FHttpModule::Get();
	FRequest_Register data;
	data.username = username;
	data.password = password;
	data.email = email;
	data.name = name;
	data.surname = surname;
	data.country = country;
	data.city = city;
	data.birthdate = birthdate;

	//Comprobamos los campos
	//bool flag=CheckInputs(username, password, cpassword, email, name, surname, country, city, birthdate);

	if (flag)
	{
		FString ContentJsonString;
		GetJsonStringFromStruct(data, ContentJsonString);

		TSharedRef<IHttpRequest> Request = http->CreateRequest();
		Request->OnProcessRequestComplete().BindUObject(this, &ARegisterHttp::OnResponesReceived);
		Request->SetURL("http://thecurseofzyn.x10host.com/GAME/insertUser.php");
		Request->SetVerb("POST");
		Request->SetContentAsString(ContentJsonString);
		Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
		Request->SetHeader("Content-Type", TEXT("application/json"));
		Request->ProcessRequest();
	}
}

void ARegisterHttp::OnResponesReceived(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(response->GetContentAsString());
	if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
		//int32 recievedInt = JsonObject->GetIntegerField("resp");
		//code = recievedInt;
		FString receivedString = JsonObject->GetStringField("resp");
		if (receivedString == "OK")
		{
			flag = true;
		}
		else
		{
			flag = false;
			error = "R0";
		}
		
	}
}


void ARegisterHttp::GetJsonStringFromStruct(FRequest_Register FilledStruct, FString & StringOutput)
{
	FJsonObjectConverter::UStructToJsonObjectString(FRequest_Register::StaticStruct(), &FilledStruct, StringOutput, 0, 0);
}

//bool ARegisterHttp::CheckInputs(FString username, FString password, FString cpassword, FString email, FString name, FString surname, FString country, FString city, FString birthday)
//{
//	flag = true;
//
//	const FRegexPattern emailPattern = (TEXT("^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$"));
//	
//
//	FRegexMatcher emailMatcher(emailPattern, email);
//	
//
//
//	//Check the name input
//	if (name.IsEmpty())
//	{
//		flag = false;
//		error = "Name input can't be empty";
//	}
//
//	//Check the surname input
//	if (surname.IsEmpty())
//	{
//		error = "Surname input can't be empty";
//		flag = false;
//	}
//
//	//Check the country input
//	if (country.IsEmpty())
//	{
//		error = "Country input can't be empty";
//		flag = false;
//	}
//
//	//Check the city input
//	if (city.IsEmpty())
//	{
//		error = "City input can't be empty";
//		flag = false;
//	}
//
//	//Check the birthdate input
//	if (birthday.IsEmpty())
//	{
//		error = "Birthdate input can't be empty";
//		flag = false;
//	}
//
//	//Check the username input
//	if (username.IsEmpty())
//	{
//		error = "Username input can't be empty";
//		flag = false;
//	}
//	else
//	{
//		if (username.Len() < 6)
//		{
//			error = "Username needs to have at least 8 characters length";
//			flag = false;
//		}
//		else {
//			//Check if the username already exists in the BBDD
//			CheckUsername(username);
//		}
//	}
//
//	//Check the password input
//	if (password.IsEmpty() || cpassword.IsEmpty())
//	{
//		error = "Pasword inputs can't be empty";
//		flag = false;
//	}
//	else
//	{
//		if (password != cpassword)
//		{
//			error = "Passwords must be equal";
//			flag = false;
//		}
//		else
//		{
//			if (!passwordMatcher.FindNext())
//			{
//				error = "Password must have 8 characters of legth minimum, at least one letter, one number  and one special character";
//			}
//		}
//	}
//
//	////Check the email input
//	//if (email.IsEmpty())
//	//{
//	//	error = "Email input can't be empty";
//	//	flag = false;
//	//}
//	//else
//	//{
//	//	if (!emailMatcher.FindNext())
//	//	{
//	//		error = "Email must be valid";
//	//		flag = false;
//	//	}
//	//	else
//	//	{
//	//		//error = "";
//	//		//Check if the email is already exists in the BBDD
//	//	}
//	//}
//
//	
//
//	return flag;
//}

void ARegisterHttp::CheckUsername(FString username)
{
	http = &FHttpModule::Get();
	FRequest_Register data;
	data.username = username;

	FString ContentJsonString;
	GetJsonStringFromStruct(data, ContentJsonString);

	TSharedRef<IHttpRequest> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ARegisterHttp::OnResponesReceivedCU);
	Request->SetURL("http://thecurseofzyn.x10host.com/GAME/checkUsername.php");
	Request->SetVerb("POST");
	Request->SetContentAsString(ContentJsonString);
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
}

void ARegisterHttp::CheckEmail(FString email)
{
	http = &FHttpModule::Get();
	FRequest_Register data;
	data.email = email;

	FString ContentJsonString;
	GetJsonStringFromStruct(data, ContentJsonString);

	TSharedRef<IHttpRequest> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ARegisterHttp::OnResponesReceivedCU);
	Request->SetURL("http://thecurseofzyn.x10host.com/GAME/checkEmail.php");
	Request->SetVerb("POST");
	Request->SetContentAsString(ContentJsonString);
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
}

void ARegisterHttp::CheckPassword(FString password, FString cpassword)
{
	flagPassword = true;
	const FRegexPattern passwordPattern = (TEXT("^(?=.*[A-Za-z])(?=.*\\d)(?=.*[$@$!%*#?&])[A-Za-z\\d$@$!%*#?&]{8,20}$"));

	FRegexMatcher passwordMatcher(passwordPattern, password);

	if (password != cpassword)
	{
		error = "P0";
		flagPassword = false;
	}
	else
	{
		if (!passwordMatcher.FindNext())
		{
			error = "P1";
			flagPassword = false;
			//error = "Password must have 8 characters of legth minimum, at least one letter, one number  and one special character";
		}
	}

}

void ARegisterHttp::OnResponesReceivedCU(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(response->GetContentAsString());
	if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
		//int32 recievedInt = JsonObject->GetIntegerField("resp");
		//code = recievedInt;
		FString receivedString = JsonObject->GetStringField("resp");
		//error = receivedString;
		if (receivedString == "BAD")
		{
			flagUsername = false;
			error = "U0";
		}
		else
		{
			flagUsername = true;
		}
	}
}

void ARegisterHttp::OnResponesReceivedCE(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessfull)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(response->GetContentAsString());
	if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
		//int32 recievedInt = JsonObject->GetIntegerField("resp");
		//code = recievedInt;
		FString receivedString = JsonObject->GetStringField("resp");
		//error = receivedString;
		if (receivedString == "BAD")
		{
			flagEmail = false;
			error = "E0";
		}
		else
		{
			flagEmail = true;
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

