#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RelicWidget.generated.h"

class UImage;
class URelic;

UCLASS()
class COURSEWORK_API URelicWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UImage* Image;

public:

	UFUNCTION()
	void SetUp(URelic* relic);
};
