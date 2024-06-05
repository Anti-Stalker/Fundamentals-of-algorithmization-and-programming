#include "PlayerStatsHUD.h"

void APlayerStatsHUD::BeginPlay()
{
	UPlayerStatsWidget* statsUI = Cast<UPlayerStatsWidget>(CreateWidget(GetWorld(), widget));
	statsUI->AddToViewport();
}