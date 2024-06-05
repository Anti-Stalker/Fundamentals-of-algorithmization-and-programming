#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOver.generated.h"

class UButton;
class UTextBlock;
class UGameManager;

UCLASS()
class COURSEWORK_API UGameOver : public UUserWidget
{
	GENERATED_BODY()
	
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* ToMainMenu;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Stats;

	UPROPERTY()
	UGameManager* manager;

	UFUNCTION()
	void ToMenu();
};
