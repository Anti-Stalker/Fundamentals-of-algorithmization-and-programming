#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "CardStruct.generated.h"

class UCardWidget;

USTRUCT()
struct COURSEWORK_API FCardStruct
{
	GENERATED_BODY()
	
	FCardStruct() = default;

	FCardStruct(UCard* card, bool upgraded = false);

	bool operator==(const FCardStruct& other) const;

	UPROPERTY()
	FString cardTitle;
	UPROPERTY()
	ECardRarity cardRarity;
	UPROPERTY()
	bool isUpgraded;
	UPROPERTY()
	bool exhaust;
	UPROPERTY()
	bool uExhaust;
	UPROPERTY()
	int cardCost;
	UPROPERTY()
	int uCardCost;
	UPROPERTY()
	int cardEffect;
	UPROPERTY()
	int uCardEffect;
	UPROPERTY()
	int repeatCount;
	UPROPERTY()
	int uRepeatCount;
	UPROPERTY()
	TArray<UBuff*> cardBuffs;
	UPROPERTY()
	TArray<UBuff*> uCardBuffs;
	UPROPERTY()
	UTexture2D* cardIcon;
	UPROPERTY()
	ECardType cardType;
	UPROPERTY()
	ECardClass cardClass;
	UPROPERTY()
	ECardPlayType cardPlayType;
	UPROPERTY()
	ECardPlayType uCardPlayType;
	UPROPERTY()
	ECardTargetType cardTargetType;

	UPROPERTY()
	UCardWidget* widget;
};
