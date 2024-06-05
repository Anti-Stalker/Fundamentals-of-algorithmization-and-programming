#include "RestWidget.h"
#include "Components/Button.h"
#include "Components/ScaleBox.h"
#include "CardSelectionWidget.h"
#include "GameManager.h"

void URestWidget::NativeConstruct()
{
	manager = Cast<UGameManager>(GetGameInstance());

	cardSelection = Cast<UCardSelectionWidget>(CreateWidget(GetWorld(), cardSelectionWidget));
	cardSelection->OnCardSelectConfirmClickedEvent.AddDynamic(this, &URestWidget::Upgrade);

	RestButton->OnClicked.AddDynamic(this, &URestWidget::ChooseRest);
	UpgradeButton->OnClicked.AddDynamic(this, &URestWidget::ChooseUpgrade);
	SelectButton->OnClicked.AddDynamic(this, &URestWidget::Select);
	ProceedButton->OnClicked.AddDynamic(this, &URestWidget::Proceed);

	CardSelectionBox->AddChild(cardSelection);
	cardSelection->SetVisibility(ESlateVisibility::Hidden);
}

void URestWidget::ChooseRest()
{
	restSelected = true;
	SelectButton->SetVisibility(ESlateVisibility::Visible);
}

void URestWidget::ChooseUpgrade()
{
	restSelected = false;
	cardSelection->SetVisibility(ESlateVisibility::Visible);
	SelectButton->SetVisibility(ESlateVisibility::Hidden);
}

void URestWidget::Select()
{
	if (restSelected)
	{
		manager->HandleHealth(manager->GetMaxHealth() * 0.3);
		RestButton->SetVisibility(ESlateVisibility::Hidden);
		UpgradeButton->SetVisibility(ESlateVisibility::Hidden);
		SelectButton->SetVisibility(ESlateVisibility::Hidden);
		ProceedButton->SetVisibility(ESlateVisibility::Visible);
		manager->SetGameState(EGameState::Map);
		manager->SaveGame();
	}
}

void URestWidget::Upgrade(FCardStruct& card)
{
	card.widget = nullptr;
	int i = manager->GetCards().Find(card);
	manager->GetCards()[i].isUpgraded = true;
	RestButton->SetVisibility(ESlateVisibility::Hidden);
	UpgradeButton->SetVisibility(ESlateVisibility::Hidden);
	SelectButton->SetVisibility(ESlateVisibility::Hidden);
	ProceedButton->SetVisibility(ESlateVisibility::Visible);
	manager->SetGameState(EGameState::Map);
	manager->SaveGame();
}

void URestWidget::Proceed()
{
	manager->LoadLevel();
}
