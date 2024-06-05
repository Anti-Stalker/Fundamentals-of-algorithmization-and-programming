#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardSelectionWidget.generated.h"

struct FCardStruct;

class UCardWidget;
class UGameManager;
class UGridPanel;
class UButton;
class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardSelectConfirmClicked, FCardStruct&, Card);

UCLASS()
class COURSEWORK_API UCardSelectionWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> cardWidget;

	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UGridPanel* CardPanel;
	UPROPERTY(meta = (BindWidget))
	UButton* Select;
	UPROPERTY(meta = (BindWidget))
	UButton* Return;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SelectText;

	UPROPERTY()
	UGameManager* manager;
	UPROPERTY()
	TArray<FCardStruct> cards;
	UPROPERTY()
	bool onlyNonUpgraded;
	UPROPERTY()
	bool cancellable;
	UPROPERTY()
	UCardWidget* selected;
	UPROPERTY()
	TArray<FCardStruct> customCards;

	UFUNCTION()
	void SelectCard(UCardWidget* Card);
	UFUNCTION()
	void Back();
	UFUNCTION()
	void Confirm();

public:
	FOnCardSelectConfirmClicked OnCardSelectConfirmClickedEvent;

	UFUNCTION()
	void SetupCards(bool custom);
	UFUNCTION()
	void SetCustomCards(TArray<UCard*> custom);
};
