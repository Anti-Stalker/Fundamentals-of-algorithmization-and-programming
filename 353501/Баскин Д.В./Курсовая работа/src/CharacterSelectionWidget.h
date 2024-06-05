#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterSelectionWidget.generated.h"

class UButton;
class UGameManager;
class UGameCharacter;

UCLASS()
class COURSEWORK_API UCharacterSelectionWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<UGameCharacter*> characters;
	
	UPROPERTY(meta = (BindWidget));
	UButton* bCharacterChad;
	UPROPERTY(meta = (BindWidget));
	UButton* bCharacterVadim;
	UPROPERTY(meta = (BindWidget));
	UButton* bEmbark;

	UPROPERTY()
	UGameCharacter* selection = nullptr;
	UPROPERTY()
	UGameManager* manager;

	void NativeConstruct() override;

	UFUNCTION()
	void SelectChad();
	UFUNCTION()
	void SelectVadim();
	UFUNCTION()
	void Embark();
};
