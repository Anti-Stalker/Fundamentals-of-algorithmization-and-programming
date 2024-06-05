#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardHandWidget.generated.h"

class UOverlay;
class UCardWidget;

UCLASS()
class COURSEWORK_API UCardHandWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCardWidget> cardWidget;

public:

	UPROPERTY(meta = (BindWidget))
	UOverlay* CardHandOverlay;

	UFUNCTION()
	void AddCard(FCardStruct& card);
	UFUNCTION()
	void RemoveCard(FCardStruct& card);
	UFUNCTION()
	void SelectCard(UCardWidget* Card);

	UFUNCTION()
	void UpdateCardPositions();

	UFUNCTION()
	FWidgetTransform CalculateCardPosition(UWidget* card, int i);
};
