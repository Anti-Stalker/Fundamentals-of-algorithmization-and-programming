#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PotionWidget.generated.h"

class UImage;
class UMenuAnchor;
class UButton;
class UPotion;

UCLASS()
class COURSEWORK_API UPotionWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UImage* Image;
	UPROPERTY(meta = (BindWidget))
	UMenuAnchor* Menu;
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY()
	UPotion* potion;

public:

	UFUNCTION()
	void OpenMenu();
	UFUNCTION()
	void SetUp(UPotion* ref);
};
