#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "Relic.h"
#include "Enemy.h"
#include "Engine/DataAsset.h"
#include "EventOption.generated.h"

UCLASS()
class COURSEWORK_API UEventOption : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString text;
	UPROPERTY(EditAnywhere)
	FString afterText;
	UPROPERTY(EditAnywhere)
	bool healthPercentage;
	UPROPERTY(EditAnywhere)
	bool maxHealth;
	UPROPERTY(EditAnywhere)
	int healthChange;
	UPROPERTY(EditAnywhere)
	int goldChange;
	UPROPERTY(EditAnywhere)
	UCard* curseToObtain;
	UPROPERTY(EditAnywhere)
	URelic* relicToObtain;
};