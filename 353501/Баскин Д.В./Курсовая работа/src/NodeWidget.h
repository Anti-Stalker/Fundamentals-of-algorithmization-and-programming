#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NodeStruct.h"
#include "NodeWidget.generated.h"

class UGameManager;
class UButton;
class UImage;

UCLASS()
class COURSEWORK_API UNodeWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;

	UFUNCTION()
	void LoadNodeContent();

public:
	UPROPERTY(meta = (BindWidget));
	UButton* button;
	UPROPERTY(meta = (BindWidget));
	UImage* image;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* Purge;
	UPROPERTY()
	FRandomStream seed;
	UPROPERTY()
	ENodeType type;

	UFUNCTION()
	void StartPurge();
};
