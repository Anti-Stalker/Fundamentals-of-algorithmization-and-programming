#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EventWidget.generated.h"

class UGameManager;
class UImage;
class UVerticalBox;
class UTextBlock;
class UEventAsset;
class UButton;
class UChooseButton;

UCLASS()
class COURSEWORK_API UEventWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UChooseButton> chooseButtonWidget;
	UPROPERTY(EditAnywhere)
	TArray<UEventAsset*> events;

	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UImage* Image;
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* OptionsBox;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text;
	UPROPERTY(meta = (BindWidget))
	UButton* Proceed;

	UPROPERTY()
	UGameManager* manager;
	UPROPERTY()
	FRandomStream seed;

	UPROPERTY()
	UEventAsset* event;

	UFUNCTION()
	UChooseButton* CreateButton();
	UFUNCTION()
	FString GenerateTooltip(int index);
	UFUNCTION()
	void ChooseOption(UChooseButton* optionButton);
	UFUNCTION()
	void Continue();
};
