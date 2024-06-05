#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CharacterClass.h"
#include "MapStruct.h"
#include "Potion.h"
#include "EventAsset.h"
#include "PlayerStats.generated.h"

UENUM()
enum class EGameState
{
	Map,
	RestSide,
	Shop,
	Battle,
	EventBattle,
	EliteBattle,
	BossBattle,
	TreasureRoom,
	Event,
	Over
};

UCLASS()
class COURSEWORK_API UPlayerStats : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPlayerStats();

	UPROPERTY()
	FRandomStream seed;
	UPROPERTY()
	int health;
	UPROPERTY()
	int maxHealth;
	UPROPERTY()
	int maxEnergy;
	UPROPERTY()
	int gold;
	UPROPERTY()
	int currentFloor;
	UPROPERTY()
	ECharacterClass character;
	UPROPERTY()
	UTexture2D* art;
	UPROPERTY()
	TArray<FCardStruct> cards;
	UPROPERTY()
	TArray<URelic*> relics;
	UPROPERTY()
	TArray<UPotion*> potions;
	UPROPERTY()
	FMapStruct map;
	UPROPERTY()
	EGameState gameState;
	UPROPERTY()
	TArray<UEventAsset*> encounteredEvents;
	UPROPERTY()
	int currentColumn;
};
