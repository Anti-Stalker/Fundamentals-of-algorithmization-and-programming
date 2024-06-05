#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardStruct.h"
#include "ShopWidget.generated.h"

class UGameManager;
class UCardWidget;
class UImage;
class UButton;
class UHorizontalBox;
class URelic;
class UCardSelectionWidget;
class UScaleBox;
class UTextBlock;
class UOverlay;

UCLASS()
class COURSEWORK_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> cardWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> cardSelectionWidget;

	UPROPERTY(EditAnywhere)
	TArray<URelic*> relicsPull;
	UPROPERTY(EditAnywhere)
	TArray<UCard*> cardsCSC;
	UPROPERTY(EditAnywhere)
	TArray<UCard*> cardsGSRLE;
	UPROPERTY(EditAnywhere)
	TArray<UCard*> cardsColorless;

	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UButton* Button;
	UPROPERTY(meta = (BindWidget))
	UButton* Relic1;
	UPROPERTY(meta = (BindWidget))
	UButton* Relic2;
	UPROPERTY(meta = (BindWidget))
	UImage* Relic1Image;
	UPROPERTY(meta = (BindWidget))
	UImage* Relic2Image;
	UPROPERTY(meta = (BindWidget))
	UButton* Card1;
	UPROPERTY(meta = (BindWidget))
	UButton* Card2;
	UPROPERTY(meta = (BindWidget))
	UButton* Card3;
	UPROPERTY(meta = (BindWidget))
	UOverlay* Card1O;
	UPROPERTY(meta = (BindWidget))
	UOverlay* Card2O;
	UPROPERTY(meta = (BindWidget))
	UOverlay* Card3O;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Price1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Price2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Price3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Price4;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Price5;
	UPROPERTY(meta = (BindWidget))
	UButton* CardRemove;
	UPROPERTY(meta = (BindWidget))
	UButton* Proceed;
	UPROPERTY(meta = (BindWidget))
	UScaleBox* CardSelectionBox;

	UPROPERTY()
	UCardSelectionWidget* cardSelection;

	UPROPERTY()
	int selection;
	UPROPERTY()
	TArray<FCardStruct> cards;
	UPROPERTY()
	TArray<URelic*> relics;
	UPROPERTY()
	TArray<int> cost;

	UPROPERTY()
	UGameManager* manager;
	UPROPERTY()
	FRandomStream seed;

	UFUNCTION()
	void GenerateContent();
	UFUNCTION()
	void Select0();
	UFUNCTION()
	void Select1();
	UFUNCTION()
	void Select2();
	UFUNCTION()
	void Select3();
	UFUNCTION()
	void Select4();
	UFUNCTION()
	void Select5();
	UFUNCTION()
	void Select6();
	UFUNCTION()
	void CardRemoval(FCardStruct& card);
	UFUNCTION()
	void Confirm();
};
