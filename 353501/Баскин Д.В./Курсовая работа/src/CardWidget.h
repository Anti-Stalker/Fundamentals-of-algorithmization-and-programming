#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardStruct.h"
#include "CardWidget.generated.h"

class UImage;
class UTextBlock;
class UButton;
class UWidgetAnimation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardClicked, UCardWidget*, CardClicked);

UCLASS()
class COURSEWORK_API UCardWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UImage* CardBackground;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CardNameText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CardCostText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CardDescriptionText;
	UPROPERTY(meta = (BindWidget))
	UImage* CardImage;
	UPROPERTY(meta = (BindWidget))
	UButton* Button;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* Selected;
	
public:

	UPROPERTY()
	FOnCardClicked OnCardClickedEvent;

	UFUNCTION()
	void Clicked();
	UFUNCTION()
	void PlayClickAnimation();

	UFUNCTION()
	void SetName(FString& name);
	UFUNCTION()
	void SetCost(int cost);
	UFUNCTION()
	void SetDescription(FString& description);
	UFUNCTION()
	void SetImage(UTexture2D* image);
	UFUNCTION()
	void SetupCard(FCardStruct& card);
};
