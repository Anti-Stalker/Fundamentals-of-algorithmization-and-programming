#include "CharacterSelectionWidget.h"
#include <Components/Button.h>
#include "GameManager.h"

void UCharacterSelectionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	manager = Cast<UGameManager>(GetGameInstance());
	bCharacterChad->OnClicked.AddDynamic(this, &UCharacterSelectionWidget::SelectChad);
	bCharacterVadim->OnClicked.AddDynamic(this, &UCharacterSelectionWidget::SelectVadim);
	bEmbark->OnClicked.AddDynamic(this, &UCharacterSelectionWidget::Embark);
}

void UCharacterSelectionWidget::SelectChad()
{
	selection = characters[0];
	bCharacterVadim->SetIsEnabled(true);
	bCharacterChad->SetIsEnabled(false);
}

void UCharacterSelectionWidget::SelectVadim()
{
	selection = characters[1];
	bCharacterVadim->SetIsEnabled(false);
	bCharacterChad->SetIsEnabled(true);
}

void UCharacterSelectionWidget::Embark()
{
	if (selection != nullptr)
	{
		manager->SaveGame();

		manager->Initialize(selection->startHealth, 3, selection->startRelic, selection->startingDeck, selection->characterClass, selection->art);
		manager->SetGameState(EGameState::Map);

		manager->SaveGame();
		manager->LoadLevel();
	}
}