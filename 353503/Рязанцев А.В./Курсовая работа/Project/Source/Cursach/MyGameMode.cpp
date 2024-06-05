// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

AMyGameMode::AMyGameMode()
{
	HUDClass = ACharacterHUD::StaticClass();
}

void AMyGameMode::BeginPlay() {
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "EEEEEeeEEEEE");

	
}
