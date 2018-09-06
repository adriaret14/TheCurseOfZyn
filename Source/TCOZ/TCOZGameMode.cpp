// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TCOZGameMode.h"
#include "TCOZPlayerController.h"
#include "TCOZCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATCOZGameMode::ATCOZGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATCOZPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}