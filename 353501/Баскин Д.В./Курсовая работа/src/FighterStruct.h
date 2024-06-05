#pragma once

#include "CoreMinimal.h"
#include "BuffStruct.h"
#include "FighterStruct.generated.h"

class UFighterWidget;
class UEnemyAction;

USTRUCT()
struct COURSEWORK_API FFighterStruct
{
	GENERATED_BODY()

public:

	FFighterStruct() = default;

	FFighterStruct(int health, int maxHealth, int block, TArray<FBuffStruct> buffs, UTexture2D* visuals, bool isPlayer = false);

	bool operator==(const FFighterStruct& other) const;

	UPROPERTY()
	bool isPlayer = false;

	UPROPERTY()
	int currentHealth;
	UPROPERTY()
	int maxHealth;
	UPROPERTY()
	int currentBlock;
	UPROPERTY()
	TArray<FBuffStruct> buffs;
	UPROPERTY()
	UTexture2D* visuals;

	UPROPERTY()
	TArray<UEnemyAction*> possibleActions;
	UPROPERTY()
	FRandomStream seed;
	UPROPERTY()
	UEnemyAction* intent;

	UPROPERTY()
	UFighterWidget* widget;
};
