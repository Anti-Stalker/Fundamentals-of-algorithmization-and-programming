#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LootWidget.generated.h"

class UChooseButton;
class UCardSelectionWidget;
class UGameManager;
class UButton;
class UVerticalBox;
class UImage;
class UCard;
class UPotion;
class UScaleBox;
class URelic;
class UWidgetAnimation;

UCLASS()
class COURSEWORK_API ULootWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCardSelectionWidget> cardSelectionWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UChooseButton> lootButtonWidget;
	UPROPERTY(EditAnywhere)
	TArray<URelic*> obtainableRelics;
	UPROPERTY(EditAnywhere)
	TArray<UCard*> obtainableCSCCards;
	UPROPERTY(EditAnywhere)
	TArray<UCard*> obtainableGSRLCards;
	UPROPERTY(EditAnywhere)
	TArray<UPotion*> obtainablePotions;
	UPROPERTY(EditAnywhere)
	UTexture2D* goldImage;

	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UButton* ProceedButton;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* LootBox;
	UPROPERTY(meta = (BindWidget))
	UScaleBox* CardSelectionBox;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* FullSlots;

	UPROPERTY()
	TArray<UCard*> cardsLoot;
	UPROPERTY()
	URelic* relicLoot;
	UPROPERTY()
	TArray<UPotion*> potionsLoot;
	UPROPERTY()
	int goldLoot;

	UPROPERTY()
	UChooseButton* goldLootButton;
	UPROPERTY()
	TArray<UChooseButton*> potionLootButtons;
	UPROPERTY()
	UChooseButton* relicLootButton;
	UPROPERTY()
	UChooseButton* cardLootButton;
	UPROPERTY()
	UCardSelectionWidget* cardSelection;

	UPROPERTY()
	UGameManager* manager;
	UPROPERTY()
	FRandomStream seed;
	UPROPERTY()
	EGameState state;

	UFUNCTION()
	UChooseButton* CreateButton();
	UFUNCTION()
	void GenerateBattleLoot(bool elite);
	UFUNCTION()
	void GenerateTreasureLoot();

	UFUNCTION()
	void AddLootCard(FCardStruct& card);
	UFUNCTION()
	void CollectLoot(UChooseButton* lootButton);
	UFUNCTION()
	void Proceed();
};