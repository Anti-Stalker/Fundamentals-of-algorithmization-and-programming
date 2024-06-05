#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidget.generated.h"

struct FFighterStruct;
struct FCardStruct;

class UButton;
class UImage;
class UHorizontalBox;
class UCardHandWidget;
class UGameManager;
class UFighterWidget;
class UCardWidget;
class UOverlay;
class UTextBlock;
class UWidgetAnimation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndTurnClicked);

UCLASS()
class COURSEWORK_API UBattleWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UFighterWidget> fighterWidget;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* NotEnoughEnergy;

public:

	UPROPERTY(meta = (BindWidget))
	UImage* Background;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* PlayerFighterBox;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* EnemyFightersBox;

	UPROPERTY()
	FOnEndTurnClicked OnEndTurnClickedEvent;

	UPROPERTY(meta = (BindWidget))
	UCardHandWidget* CardHand;
	UPROPERTY(meta = (BindWidget))
	UButton* EndTurnButton;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextEnergy;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDraw;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextDiscard;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextExhaust;

	UFUNCTION()
	void OnEndTurnButtonClicked();

	UPROPERTY()
	UGameManager* manager;
	UPROPERTY()
	UFighterWidget* playerFighter;
	UPROPERTY()
	TArray<UFighterWidget*> enemyFighters;

	UFUNCTION()
	UFighterWidget* AddFighter(FFighterStruct& fighter);
	UFUNCTION()
	void RemoveFighter(FFighterStruct& fighter);
	UFUNCTION()
	void UpdateFighter(FFighterStruct& fighter);

	UFUNCTION()
	UCardWidget* AddCardToHand(FCardStruct& card);
	UFUNCTION()
	void RemoveCardFromHand(FCardStruct& card);
	UFUNCTION()
	void UpdateEnergyNumber(int to);
	UFUNCTION()
	void UpdateDrawNumber(int to);
	UFUNCTION()
	void UpdateDiscardNumber(int to);
	UFUNCTION()
	void UpdateExhaustNumber(int to);

	UFUNCTION()
	void PlayNotEnoughEnergy();
};
