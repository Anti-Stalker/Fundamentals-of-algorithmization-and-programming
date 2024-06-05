#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FighterStruct.h"
#include "CardStruct.h"
#include "BattleMode.generated.h"

class UEnemy;
class UCardWidget;
class UBattleWidget;
class UGameManager;
class UFighterWidget;
class ULootWidget;

UENUM()
enum class ETurn
{
	Player,
	Enemies
};

UCLASS()
class COURSEWORK_API ABattleMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<ULootWidget> lootWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> hudWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBattleWidget> bwidget;

	void BeginPlay() override;
	
	UPROPERTY()
	FRandomStream deckSeed;
	UPROPERTY()
	TArray<FCardStruct> drawPile;
	UPROPERTY()
	TArray<FCardStruct> cardsInHand;
	UPROPERTY()
	TArray<FCardStruct> discardPile;
	UPROPERTY()
	TArray<FCardStruct> exhaustPile;

	UPROPERTY()
	UCardWidget* selectedCard;

	UPROPERTY()
	UBattleWidget* battleWidget;
	UPROPERTY()
	UGameManager* manager;

	UPROPERTY()
	FFighterStruct playerFighter;
	UPROPERTY()
	TArray<FFighterStruct> enemyFighters;

	UPROPERTY()
	int energy;
	UPROPERTY()
	int drawAmount = 5;
	UPROPERTY()
	ETurn turn = ETurn::Enemies;
	UPROPERTY()
	int turnNumber;
	UPROPERTY()
	FRandomStream randomSeed;

	UPROPERTY(EditAnywhere)
	TArray<UEnemy*> possibleActEnemies;
	UPROPERTY(EditAnywhere)
	TArray<UEnemy*> possibleActEliteEnemies;
	UPROPERTY(EditAnywhere)
	TArray<UEnemy*> bosses;

	UFUNCTION()
	void InitPlayer();
	UFUNCTION()
	void InitEnemy(UEnemy* enemy);
	UFUNCTION()
	void GenerateNextIntent(FFighterStruct& enemy);
	UFUNCTION()
	void RemoveEnemy(FFighterStruct& enemy);

	UFUNCTION()
	void UpdatePlayerFighter();
	UFUNCTION()
	void HandleTurn();
	UFUNCTION()
	void PerformEnemyIntent(FFighterStruct& enemy);

	UFUNCTION()
	void CardEffect(FCardStruct& card, FFighterStruct& fighter, int effect, int repeatCount);
	UFUNCTION()
	void CardBuffs(FCardStruct& card, TArray<FBuffStruct>& buffs, FFighterStruct& fighter, int repeatCount);
	UFUNCTION()
	void ApplyBuff(FFighterStruct& fighter, FBuffStruct& buff);
	UFUNCTION()
	void ApplyDamage(FFighterStruct attacker, FFighterStruct& defender, int amount, bool passive = false);
	UFUNCTION()
	void ApplyBlock(FFighterStruct& fighter, int amount);
	UFUNCTION()
	void ReduceBuffs(FFighterStruct& fighter);
	UFUNCTION()
	void UseEnergy(int amount);
	UFUNCTION()
	void PotionUse(UPotion* potion);

	UFUNCTION()
	FFighterStruct& FindFighter(UFighterWidget* Fighter);

	UFUNCTION()
	void SelectCard(UCardWidget* Card);
	UFUNCTION()
	void SelectFighter(UFighterWidget* Fighter);
	UFUNCTION()
	void PlayCard(FCardStruct& card, FFighterStruct& fighter);
	UFUNCTION()
	void DiscardCard(FCardStruct& card);
	UFUNCTION()
	void ExhaustCard(FCardStruct& card);
	UFUNCTION()
	void DrawCard();
	UFUNCTION()
	void ShuffleDiscardToDraw();

	UFUNCTION()
	void EndFight();
};
