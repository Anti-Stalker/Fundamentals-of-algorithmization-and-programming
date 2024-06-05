#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayMode.generated.h"

class UGameManager;
class UUserWidget;

UCLASS()
class COURSEWORK_API AGameplayMode : public AGameModeBase
{
	GENERATED_BODY()

	void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> hudWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> mapWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> restWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> shopWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> treasureWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> eventWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> overWidget;

	UPROPERTY()
	UGameManager* manager;
};
