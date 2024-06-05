#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Relic.h"
#include "CardStruct.h"
#include "CharacterClass.generated.h"

UENUM()
enum class ECharacterClass
{
	ComputerScienceChad,
	GomelStateRegionalLyceumEnjoyer
};

UCLASS()
class COURSEWORK_API UGameCharacter : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	ECharacterClass characterClass;

	UPROPERTY(EditAnywhere)
	int startHealth;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* flipbook;

	UPROPERTY(EditAnywhere)
	URelic* startRelic;

	UPROPERTY(EditAnywhere)
	UTexture2D* art;

	UPROPERTY(EditAnywhere)
	TArray<UCard*> startingDeck;
};
