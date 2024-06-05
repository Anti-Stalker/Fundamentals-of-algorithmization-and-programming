#include "GameplayMode.h"
#include "GameManager.h"
#include "Blueprint/UserWidget.h"

void AGameplayMode::BeginPlay()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();

	UUserWidget* widget = nullptr;

	manager = Cast<UGameManager>(GetGameInstance());
	switch (manager->GetGameState())
	{
	case EGameState::Map:
		if (manager->GetFloor() == 10)
		{
			manager->HandleFloor();
		}
		widget = CreateWidget(GetWorld(), mapWidget);
		break;
	case EGameState::RestSide:
		widget = CreateWidget(GetWorld(), restWidget);
		break;
	case EGameState::Shop:
		widget = CreateWidget(GetWorld(), shopWidget);
		break;
	case EGameState::TreasureRoom:
		widget = CreateWidget(GetWorld(), treasureWidget);
		break;
	case EGameState::Event:
		widget = CreateWidget(GetWorld(), eventWidget);
		break;
	case EGameState::Over:
		widget = CreateWidget(GetWorld(), overWidget);
		break;
	default:
		break;
	}

	if (widget == nullptr)
	{
		return;
	}
	widget->AddToViewport();

	UUserWidget* hud = CreateWidget(GetWorld(), hudWidget);
	hud->AddToViewport();
	controller->SetShowMouseCursor(true);
}