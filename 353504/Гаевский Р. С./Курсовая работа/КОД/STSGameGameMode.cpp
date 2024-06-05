// Copyright Epic Games, Inc. All Rights Reserved.

#include "STSGameGameMode.h"
#include "STSGamePlayerController.h"
#include "STSGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASTSGameGameMode::ASTSGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARTSGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/RTSOverseerer_BP"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}