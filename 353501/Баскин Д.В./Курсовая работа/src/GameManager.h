#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerStats.h"
#include "GameManager.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerStatChange);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPotionUsed, UPotion*, potion);

UCLASS()
class COURSEWORK_API UGameManager : public UGameInstance
{
	GENERATED_BODY()

	UFUNCTION()
	void GenerateMap();
	UFUNCTION()
	void GenerateActNodes(TArray<FFloorStruct> &act);
	UFUNCTION()
	void GenerateActNodesContent(TArray<FFloorStruct>& act);
	UFUNCTION()
	void GenerateNodeContent(FNodeStruct& node);
	UFUNCTION()
	void FixContentGeneration(TArray<FFloorStruct>& act);
	UFUNCTION()
	bool CheckChainRuleBreak(FNodeStruct& from, FNodeStruct& to);
	UFUNCTION()
	void GenerateConstFloor(TArray<FFloorStruct>& act, int floor, ENodeType type);
	
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
	int currentColumn;
	UPROPERTY()
	TArray<UEventAsset*> encounteredEvents;

	UPROPERTY()
	FRandomStream seed;
	UPROPERTY()
	EGameState gameState;
	
	UPROPERTY()
	UPotion* selectedPotion;

	virtual void Init() override;

public:

	UPROPERTY()
	FOnPlayerStatChange OnPlayerStatChangeEvent;
	UPROPERTY()
	FOnPotionUsed OnPotionUsedEvent;

	UFUNCTION()
	void Initialize(int startHealth, int startEnergy, URelic* startingRelic, TArray<UCard*> startingDeck, ECharacterClass characterClass, UTexture2D* characterArt);
	UFUNCTION()
	void EndGame();

	UFUNCTION()
	void HandleHealth(int change);
	UFUNCTION()
	void HandleMaxHealth(int change);
	UFUNCTION()
	void HandleFloor(bool set = false, int to = 0);
	UFUNCTION()
	bool HandleGold(int change, bool checkOnly = false);
	UFUNCTION()
	void HandleActiveNodes();

	UFUNCTION()
	int GetHealth();
	UFUNCTION()
	int GetMaxHealth();
	UFUNCTION()
	int GetGold();
	UFUNCTION()
	int GetFloor();
	UFUNCTION()
	int GetMaxEnergy();

	UFUNCTION()
	FMapStruct& GetMap();
	UFUNCTION()
	TArray<FNodeStruct>& GetActiveNodes();
	UFUNCTION()
	TArray<FCardStruct>& GetCards();
	UFUNCTION()
	TArray<URelic*>& GetRelics();
	UFUNCTION()
	TArray<UPotion*>& GetPotions();
	UFUNCTION()
	TArray<UEventAsset*>& GetEncounteredEvents();
	UFUNCTION()
	void AddEncounteredEvent(UEventAsset* event);
	UFUNCTION()
	FRandomStream& GetSeed();
	UFUNCTION()
	void SetSeed(FRandomStream& newSeed);
	UFUNCTION()
	void SetCurrentColumn(int column);
	UFUNCTION()
	ECharacterClass GetCharacter();
	UFUNCTION()
	EGameState GetGameState();
	UFUNCTION()
	UTexture2D* GetArt();
	UFUNCTION()
	void SetArt(UTexture2D* newArt);
	UFUNCTION()
	void SetGameState(EGameState newGameState);
	UFUNCTION()
	void AddCard(FCardStruct& card);
	UFUNCTION()
	void RemoveCard(FCardStruct& card);
	UFUNCTION()
	void AddRelic(URelic* relic);
	UFUNCTION()
	bool HasRelic(FString name);
	UFUNCTION()
	void RemoveRelic(URelic* relic);
	UFUNCTION()
	bool AddPotion(UPotion* potion);
	UFUNCTION()
	void RemovePotion(UPotion* potion);

	UFUNCTION()
	void UsePotion();
	UFUNCTION()
	UPotion* GetSelectedPotion();
	UFUNCTION()
	void SetSelectedPotion(UPotion* potion);

	UFUNCTION()
	void LoadLevel();

	UFUNCTION()
	void CreateSaveFile();
	UFUNCTION()
	void SaveGame();
	UFUNCTION()
	void LoadGame();
	UFUNCTION()
	void DeleteSaveFile();
	UFUNCTION()
	bool HasSave();
};
