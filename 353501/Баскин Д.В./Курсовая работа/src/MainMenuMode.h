#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuMode.generated.h"

class UUserWidget;

UCLASS()
class COURSEWORK_API AMainMenuMode : public AGameModeBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> widget;

	void BeginPlay() override;
};
