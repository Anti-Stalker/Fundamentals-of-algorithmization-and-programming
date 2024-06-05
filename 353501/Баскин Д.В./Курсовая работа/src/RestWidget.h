#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardStruct.h"
#include "RestWidget.generated.h"

class UGameManager;
class UButton;
class UCardSelectionWidget;
class UScaleBox;

UCLASS()
class COURSEWORK_API URestWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> cardSelectionWidget;
	
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* RestButton;
	UPROPERTY(meta = (BindWidget))
	UButton* UpgradeButton;
	UPROPERTY(meta = (BindWidget))
	UButton* SelectButton;
	UPROPERTY(meta = (BindWidget))
	UButton* ProceedButton;
	UPROPERTY(meta = (BindWidget))
	UScaleBox* CardSelectionBox;

	UPROPERTY()
	UGameManager* manager;
	UPROPERTY()
	UCardSelectionWidget* cardSelection;

	UPROPERTY()
	bool restSelected;
	UPROPERTY()
	int selectedCard;

	UFUNCTION()
	void ChooseRest();
	UFUNCTION()
	void ChooseUpgrade();
	UFUNCTION()
	void Select();
	UFUNCTION()
	void Upgrade(FCardStruct& card);
	UFUNCTION()
	void Proceed();
};
