#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuWidget.generated.h"

class UGameManager;
class UButton;

UCLASS()
class COURSEWORK_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget));
	UButton* bContinue;

	UPROPERTY(meta = (BindWidget));
	UButton* bNew;

	UPROPERTY(meta = (BindWidget));
	UButton* bQuit;

	UGameManager* manager;

	void NativeConstruct() override;

	UFUNCTION()
	void Continue();
	UFUNCTION()
	void NewGame();
	UFUNCTION()
	void Quit();
};