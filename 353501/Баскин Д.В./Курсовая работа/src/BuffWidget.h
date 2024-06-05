#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuffWidget.generated.h"

struct FBuffStruct;

class UImage;
class UTextBlock;

UCLASS()
class COURSEWORK_API UBuffWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UImage* Image;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text;

public:

	UFUNCTION()
	void SetUp(FBuffStruct& buff);
};
