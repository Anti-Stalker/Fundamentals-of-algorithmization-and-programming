#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyAction.h"
#include "Enemy.generated.h"

UCLASS()
class COURSEWORK_API UEnemy : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	UTexture2D* art;
	UPROPERTY(EditAnywhere)
	FString name;
	UPROPERTY(EditAnywhere)
	int health;
	UPROPERTY(EditAnywhere)
	int maxHealth;
	UPROPERTY(EditAnywhere)
	TArray<UBuff*> startBuffs;
	UPROPERTY(EditAnywhere)
	bool hasOrderedActions;
	UPROPERTY(EditAnywhere)
	TArray<UEnemyAction*> possibleMoves;
};
