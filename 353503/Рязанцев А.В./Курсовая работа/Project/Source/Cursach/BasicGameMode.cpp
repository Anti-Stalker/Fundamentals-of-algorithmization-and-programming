// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicGameMode.h"

ABasicGameMode::ABasicGameMode()
{
	HUDClass = ACharacterHUD::StaticClass();
	//DefaultPawnClass = AMainCharacter::
}

void ABasicGameMode::BeginPlay() {
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "EEEEEeeEEEEE");
}
