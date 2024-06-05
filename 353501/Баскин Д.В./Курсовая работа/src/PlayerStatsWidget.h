#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatsWidget.generated.h"

class UTextBlock;
class UHorizontalBox;
class UGameManager;
class UImage;
class URelicWidget;

UCLASS()
class COURSEWORK_API UPlayerStatsWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> relicWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> potionWidget;

	void NativeConstruct() override;

	UFUNCTION()
	void UpdateInfo();

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ClassText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HPText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* GoldText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* FloorText;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* PotionsBox;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* RelicsBox;
	UPROPERTY(meta = (BindWidget))
	UButton* ToMenu;

	UPROPERTY()
	UGameManager* manager;

	UFUNCTION()
	void Menu();
};
