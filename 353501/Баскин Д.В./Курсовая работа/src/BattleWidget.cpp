#include "BattleWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "CardHandWidget.h"
#include "FighterWidget.h"
#include "FighterStruct.h"
#include "BuffStruct.h"
#include "Buff.h"
#include "Components/HorizontalBox.h"
#include "EnemyAction.h"
#include "GameManager.h"
#include "BuffWidget.h"
#include "CardWidget.h"

void UBattleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	manager = Cast<UGameManager>(GetGameInstance());

	EndTurnButton->OnClicked.AddDynamic(this, &UBattleWidget::OnEndTurnButtonClicked);
}

void UBattleWidget::OnEndTurnButtonClicked()
{
	OnEndTurnClickedEvent.Broadcast();
}

UFighterWidget* UBattleWidget::AddFighter(FFighterStruct& fighter)
{
	UFighterWidget* Fighter = Cast<UFighterWidget>(CreateWidget(GetWorld(), fighterWidget));
	fighter.widget = Fighter;
	Fighter->SetFighter(fighter.visuals);

	UpdateFighter(fighter);

	if (fighter.isPlayer)
	{
		fighter.widget->SetIntention();
		PlayerFighterBox->AddChildToHorizontalBox(Fighter);
	}
	else
	{
		EnemyFightersBox->AddChildToHorizontalBox(Fighter);
	}

	return Fighter;
}

void UBattleWidget::RemoveFighter(FFighterStruct& fighter)
{
	fighter.widget->RemoveFromParent();
	fighter.widget = nullptr;
}

void UBattleWidget::UpdateFighter(FFighterStruct& fighter)
{
	for (auto& buff : fighter.buffs)
	{
		if (buff.widget == nullptr)
		{
			continue;
		}
		buff.widget->RemoveFromParent();
		buff.widget = nullptr;
	}
	fighter.widget->SetHealth(fighter.currentHealth, fighter.maxHealth);
	fighter.widget->SetBlock(fighter.currentBlock);
	if (!fighter.isPlayer)
	{
		fighter.widget->SetIntention(fighter.intent->actionIcon, fighter.intent->amount);
	}
	fighter.widget->AddBuffs(fighter.buffs);
}

UCardWidget* UBattleWidget::AddCardToHand(FCardStruct& card)
{
	CardHand->AddCard(card);
	return card.widget;
}

void UBattleWidget::RemoveCardFromHand(FCardStruct& card)
{
	CardHand->RemoveCard(card);
}

void UBattleWidget::UpdateEnergyNumber(int to)
{
	TextEnergy->SetText(FText::AsNumber(to));
}

void UBattleWidget::UpdateDrawNumber(int to)
{
	TextDraw->SetText(FText::AsNumber(to));
}

void UBattleWidget::UpdateDiscardNumber(int to)
{
	TextDiscard->SetText(FText::AsNumber(to));
}

void UBattleWidget::UpdateExhaustNumber(int to)
{
	TextExhaust->SetText(FText::AsNumber(to));
}

void UBattleWidget::PlayNotEnoughEnergy()
{
	PlayAnimation(NotEnoughEnergy);
}
