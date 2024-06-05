#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapWidget.generated.h"

struct FFloorStruct;

class UScrollBox;
class UHorizontalBox;
class UNodeWidget;
class UGameManager;

UCLASS()
class COURSEWORK_API UMapWidget : public UUserWidget
{
	GENERATED_BODY()
	
	void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget));
	UScrollBox* Nodes;
	UPROPERTY()
	TArray<FFloorStruct> currentFloors;

	UGameManager* manager;
};
