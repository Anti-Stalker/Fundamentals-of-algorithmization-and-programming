#include "MainMenuWidget.h"
#include "GameManager.h"
#include <Components/Button.h>

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	manager = Cast<UGameManager>(GetGameInstance());
	if (!manager->HasSave())
	{
		bContinue->SetIsEnabled(false);
	}

	bContinue->OnClicked.AddDynamic(this, &UMainMenuWidget::Continue);
	bNew->OnClicked.AddDynamic(this, &UMainMenuWidget::NewGame);
	bQuit->OnClicked.AddDynamic(this, &UMainMenuWidget::Quit);
}

void UMainMenuWidget::Continue()
{
	manager->LoadGame();
	manager->LoadLevel();
}

void UMainMenuWidget::NewGame()
{
	manager->DeleteSaveFile();
	UGameplayStatics::OpenLevel(GetWorld(), FName("ClassSelection"));
}

void UMainMenuWidget::Quit()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ConsoleCommand("quit");
}