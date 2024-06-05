#include "PotionDropdownWidget.h"
#include "Components/Button.h"
#include "GameManager.h"

void UPotionDropdownWidget::NativeConstruct()
{
	Super::NativeConstruct();

	manager = Cast<UGameManager>(GetGameInstance());
	if (manager->GetGameState() != EGameState::Battle &&
		manager->GetGameState() != EGameState::EliteBattle &&
		manager->GetGameState() != EGameState::BossBattle)
	{
		UseButton->SetIsEnabled(false);
	}

	UseButton->OnClicked.AddDynamic(this, &UPotionDropdownWidget::Use);
	DropButton->OnClicked.AddDynamic(this, &UPotionDropdownWidget::Drop);
}

void UPotionDropdownWidget::Use()
{
	manager->UsePotion();
}

void UPotionDropdownWidget::Drop()
{
	manager->RemovePotion(manager->GetSelectedPotion());
}
