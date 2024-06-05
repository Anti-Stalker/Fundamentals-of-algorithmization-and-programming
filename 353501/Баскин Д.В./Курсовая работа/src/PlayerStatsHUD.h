#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerStatsWidget.h"
#include "PlayerStatsHUD.generated.h"

UCLASS()
class COURSEWORK_API APlayerStatsHUD : public AHUD
{
	GENERATED_BODY()
	
	void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerStatsWidget> widget;
};
