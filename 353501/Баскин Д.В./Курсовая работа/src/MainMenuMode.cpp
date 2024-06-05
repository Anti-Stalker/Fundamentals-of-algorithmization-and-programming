#include "MainMenuMode.h"
#include "Blueprint/UserWidget.h"

void AMainMenuMode::BeginPlay()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	UUserWidget* menu = CreateWidget(GetWorld(), widget);
	menu->AddToViewport();
	controller->SetShowMouseCursor(true);
}