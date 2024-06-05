#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PotionDropdownWidget.generated.h"

class UGameManager;
class UButton;

UCLASS()
class COURSEWORK_API UPotionDropdownWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	UButton* UseButton;
	UPROPERTY(meta = (BindWidget))
	UButton* DropButton;

	UFUNCTION()
	void Use();
	UFUNCTION()
	void Drop();

	UPROPERTY()
	UGameManager* manager;
};
