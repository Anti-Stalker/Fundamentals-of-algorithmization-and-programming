// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"

ACharacterHUD::ACharacterHUD() : Super()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBP_Key(TEXT("/Game/Interface/Widgets/WPB_Key"));

	MainHud = WBP_Key.Class;
}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHud);
	CharacterWidget->AddToViewport();
}
