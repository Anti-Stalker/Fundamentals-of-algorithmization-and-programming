// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetKey.h"

ESlateVisibility UUserWidgetKey::CharacterHasKey()
{
	AMainCharacter* Player = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); 

	bool bGetKey = Player->bIsKey;

	if (bGetKey) {
		return ESlateVisibility::Visible;
	}
	else {
		return ESlateVisibility::Hidden;
	}
}

ESlateVisibility UUserWidgetKey::CharacterRedVase()
{
	AMainCharacter* Player = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	bool bGetvase = Player->bIsRedVase;

	if (bGetvase) {
		return ESlateVisibility::Visible;
	}
	else {
		return ESlateVisibility::Hidden;
	}
}

ESlateVisibility UUserWidgetKey::CharacterGreenVase()
{
	AMainCharacter* Player = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	bool bGetvase = Player->bIsGreenVase;

	if (bGetvase) {
		return ESlateVisibility::Visible;
	}
	else {
		return ESlateVisibility::Hidden;
	}
}

ESlateVisibility UUserWidgetKey::CharacterBlueVase()
{
	AMainCharacter* Player = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	bool bGetvase = Player->bIsBlueVase;

	if (bGetvase) {
		return ESlateVisibility::Visible;
	}
	else {
		return ESlateVisibility::Hidden;
	}
}

ESlateVisibility UUserWidgetKey::CharacterWhiteVase()
{
	AMainCharacter* Player = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	bool bGetvase = Player->bIsWhiteVase;

	if (bGetvase) {
		return ESlateVisibility::Visible;
	}
	else {
		return ESlateVisibility::Hidden;
	}
}
