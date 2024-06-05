#include "GameOver.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GameManager.h"

void UGameOver::NativeConstruct()
{
	manager = Cast<UGameManager>(GetGameInstance());
	if (manager->GetHealth() > 0)
	{
		Stats->SetText(FText::FromString("You have finished the game!!!\nYou always can play again"));
	}
	else
	{
		Stats->SetText(FText::FromString("You have lost!!!\n Try better next time?"));
	}
	ToMainMenu->OnClicked.AddDynamic(this, &UGameOver::ToMenu);
	manager->DeleteSaveFile();
}

void UGameOver::ToMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
}