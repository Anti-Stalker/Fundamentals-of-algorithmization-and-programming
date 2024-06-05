#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChooseButton.generated.h"

class UButton;
class UTextBlock;
class UImage;
class UWidgetAnimation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChooseButtonClicked, UChooseButton*, button);

UCLASS()
class COURSEWORK_API UChooseButton : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* Button;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text;
	UPROPERTY(meta = (BindWidget))
	UImage* Image;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* FullSlots;

	UFUNCTION()
	void ButtonClicked();

public:

	UPROPERTY()
	FOnChooseButtonClicked OnChooseButtonClickEvent;

	UFUNCTION()
	void PlayFullSlots();
	UFUNCTION()
	void SetUp(UTexture2D* icon, FString title, FString description);
};
