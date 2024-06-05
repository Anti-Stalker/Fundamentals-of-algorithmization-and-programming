#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuffStruct.h"
#include "Card.generated.h"

UENUM()
enum class ECardType
{
	Attack,
	Skill,
	Power,
	Status,
	Curse
};

UENUM()
enum class ECardClass
{
	ComputerScienceChad,
	GomelStateRegionalLyceumEnjoyer,
	Colorless
};

UENUM()
enum class ECardTargetType
{
	Self,
	Enemy,
	RandomEnemy,
	AllEnemies
};

UENUM()
enum class ECardPlayType
{
	Regular,
	Retain,
	Ethereal
};

UENUM()
enum class ECardRarity
{
	Common,
	Uncommon,
	Rare
};

UCLASS()
class COURSEWORK_API UCard : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString cardTitle;
	UPROPERTY(EditAnywhere)
	ECardRarity cardRarity;
	UPROPERTY(EditAnywhere)
	bool exhaust;
	UPROPERTY(EditAnywhere)
	bool uExhaust;
	UPROPERTY(EditAnywhere)
	int cardCost;
	UPROPERTY(EditAnywhere)
	int uCardCost;
	UPROPERTY(EditAnywhere)
	int cardEffect;
	UPROPERTY(EditAnywhere)
	int uCardEffect;
	UPROPERTY(EditAnywhere)
	int repeatCount;
	UPROPERTY(EditAnywhere)
	int uRepeatCount;
	UPROPERTY(EditAnywhere)
	TArray<UBuff*> cardBuffs;
	UPROPERTY(EditAnywhere)
	TArray<UBuff*> uCardBuffs;
	UPROPERTY(EditAnywhere)
	UTexture2D* cardIcon;
	UPROPERTY(EditAnywhere)
	ECardType cardType;
	UPROPERTY(EditAnywhere)
	ECardClass cardClass;
	UPROPERTY(EditAnywhere)
	ECardPlayType cardPlayType;
	UPROPERTY(EditAnywhere)
	ECardPlayType uCardPlayType;
	UPROPERTY(EditAnywhere)
	ECardTargetType cardTargetType;
};
