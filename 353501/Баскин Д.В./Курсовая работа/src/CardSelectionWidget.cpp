#include "CardSelectionWidget.h"
#include "Components/GridPanel.h"
#include "Components/Button.h"
#include "Components/GridSlot.h"
#include "Components/TextBlock.h"
#include "CardWidget.h"
#include "GameManager.h"
#include "Enemy.h"

void UCardSelectionWidget::NativeConstruct()
{
	manager = Cast<UGameManager>(GetGameInstance());
	
	if (manager->GetGameState() == EGameState::RestSide)
	{
		onlyNonUpgraded = true;
		SetupCards(false);
	}
	/*if (manager->GetGameState() != EGameState::RestSide && manager->GetGameState() != EGameState::Shop)
	{
		Return->RemoveFromParent();
	}*/
	if (manager->GetGameState() == EGameState::Shop)
	{
		SetupCards(false);
	}

	Select->OnClicked.AddDynamic(this, &UCardSelectionWidget::Confirm);
	Return->OnClicked.AddDynamic(this, &UCardSelectionWidget::Back);
}

void UCardSelectionWidget::SetupCards(bool custom)
{
	cards = (custom ? customCards : manager->GetCards());
	int n = 0;
	for (auto& card : cards)
	{
		if (onlyNonUpgraded && card.isUpgraded)
		{
			continue;
		}
		UCardWidget* Card = Cast<UCardWidget>(CreateWidget(GetWorld(), cardWidget));
		card.widget = Card;
		Card->SetupCard(card);
		UGridSlot* GridSlot = Cast<UGridSlot>(CardPanel->AddChild(Card));

		if (GridSlot != nullptr)
		{
			GridSlot->SetRow(n / 4);
			GridSlot->SetColumn(n % 4);
		}
		Card->OnCardClickedEvent.AddDynamic(this, &UCardSelectionWidget::SelectCard);
		++n;
	}
}

void UCardSelectionWidget::SetCustomCards(TArray<UCard*> custom)
{
	for (auto card : custom)
	{
		customCards.Add(card);
	}
	SetupCards(true);
}

void UCardSelectionWidget::SelectCard(UCardWidget* Card)
{
	if (selected != nullptr)
	{
		selected->SetIsEnabled(true);
	}
	selected = Card;
	selected->SetIsEnabled(false);
	SelectText->SetText(FText::FromString("Confirm"));
}

void UCardSelectionWidget::Back()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UCardSelectionWidget::Confirm()
{
	if (selected == nullptr)
	{
		return;
	}

	FCardStruct confirm;
	for (auto& card : cards)
	{
		if (card.widget == selected)
		{
			confirm = card;
			break;
		}
	}
	OnCardSelectConfirmClickedEvent.Broadcast(confirm);
	this->RemoveFromParent();
}