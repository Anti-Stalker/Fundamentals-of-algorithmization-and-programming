#include "LootWidget.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "GameManager.h"
#include "ChooseButton.h"
#include "CardSelectionWidget.h"
#include "Components/ScaleBox.h"
#include "Relic.h"

void ULootWidget::NativeConstruct()
{
	manager = Cast<UGameManager>(GetGameInstance());
	seed = manager->GetSeed();

	switch (manager->GetGameState())
	{
	case EGameState::Battle:
		GenerateBattleLoot(false);
		break;
	case EGameState::EliteBattle:
		GenerateBattleLoot(true);
		break;
	case EGameState::TreasureRoom:
		GenerateTreasureLoot();
		break;
	default:
		break;
	}
	ProceedButton->OnClicked.AddDynamic(this, &ULootWidget::Proceed);
}

UChooseButton* ULootWidget::CreateButton()
{
	UChooseButton* newLootButton = Cast<UChooseButton>(CreateWidget(GetWorld(), lootButtonWidget));
	LootBox->AddChildToVerticalBox(newLootButton);
	newLootButton->OnChooseButtonClickEvent.AddDynamic(this, &ULootWidget::CollectLoot);
	return newLootButton;
}

void ULootWidget::GenerateBattleLoot(bool elite)
{
	goldLootButton = CreateButton();
	goldLoot = (elite ? seed.RandRange(100, 150) : seed.RandRange(25, 65));
	FString goldText;
	goldText.AppendInt(goldLoot);
	goldText += " Gold";
	goldLootButton->SetUp(goldImage, goldText, "Game Currency");

	float cardRarity = seed.GetFraction();
	TArray<UCard*> cards;
	TArray<UCard*> source;
	ECardRarity rarity;
	if (manager->GetCharacter() == ECharacterClass::ComputerScienceChad)
	{
		source = obtainableCSCCards;
	}
	else if (manager->GetCharacter() == ECharacterClass::GomelStateRegionalLyceumEnjoyer)
	{
		source = obtainableGSRLCards;
	}

	if (cardRarity < 0.17)
	{
		rarity = ECardRarity::Rare;
	}
	else if (cardRarity < 0.5)
	{
		rarity = ECardRarity::Uncommon;
	}
	else
	{
		rarity = ECardRarity::Common;
	}

	for (int i = 0; i < 2;)
	{
		UCard* card = source[seed.RandRange(0, source.Num() - 1)];
		if (card->cardRarity != rarity)
		{
			continue;
		}
		cards.Add(card);
		++i;
	}

	cardLootButton = CreateButton();
	cardLootButton->SetUp(nullptr, "Choose Card", "You have a choice from 3 cards");
	cardSelection = Cast<UCardSelectionWidget>(CreateWidget(GetWorld(), cardSelectionWidget));
	cardSelection->SetCustomCards(cards);
	cardSelection->OnCardSelectConfirmClickedEvent.AddDynamic(this, &ULootWidget::AddLootCard);
	CardSelectionBox->AddChild(cardSelection);
	cardSelection->SetVisibility(ESlateVisibility::Hidden);

	for (int i = 0; i < 2; ++i)
	{
		if (seed.GetFraction() < 0.2)
		{
			continue;
		}
		potionLootButtons.Add(CreateButton());
		potionsLoot.Add(obtainablePotions[seed.RandRange(0, obtainablePotions.Num() - 1)]);
		potionLootButtons.Last()->SetUp(potionsLoot.Last()->icon, potionsLoot.Last()->name, potionsLoot.Last()->name);
	}

	if (seed.GetFraction() < 0.15)
	{
		relicLootButton = CreateButton();
		do
		{
			relicLoot = obtainableRelics[seed.RandRange(0, obtainableRelics.Num() - 1)];
		} while (manager->HasRelic(relicLoot->relicName));
		relicLootButton->SetUp(relicLoot->relicIcon, relicLoot->relicName, relicLoot->relicDescription);
	}
}

void ULootWidget::GenerateTreasureLoot()
{
	float rand = seed.GetFraction();
	if (rand < 0.33)
	{
		goldLootButton = CreateButton();
		goldLoot = seed.RandRange(100, 150);
		FString goldText;
		goldText.AppendInt(goldLoot);
		goldText += " Gold";
		goldLootButton->SetUp(goldImage, goldText, "Game Currency");
	}
	else
	{
		relicLootButton = CreateButton();
		do
		{
			relicLoot = obtainableRelics[seed.RandRange(0, obtainableRelics.Num() - 1)];
		} while (manager->HasRelic(relicLoot->relicName));
		relicLootButton->SetUp(relicLoot->relicIcon, relicLoot->relicName, relicLoot->relicDescription);
	}
}

void ULootWidget::AddLootCard(FCardStruct& card)
{
	card.widget = nullptr;
	manager->AddCard(card);
	cardLootButton->RemoveFromParent();
}

void ULootWidget::CollectLoot(UChooseButton* lootButton)
{
	if (lootButton == goldLootButton)
	{
		manager->HandleGold(goldLoot);
		lootButton->RemoveFromParent();
	}
	if (lootButton == relicLootButton)
	{
		manager->AddRelic(relicLoot);
		lootButton->RemoveFromParent();
	}
	if (lootButton == cardLootButton)
	{
		cardSelection->SetVisibility(ESlateVisibility::Visible);
	}
	for (int i = 0; i < potionLootButtons.Num(); ++i)
	{
		if (lootButton == potionLootButtons[i])
		{
			if (manager->AddPotion(potionsLoot[i]))
			{
				lootButton->RemoveFromParent();
			}
			else
			{
				lootButton->PlayFullSlots();
				PlayAnimation(FullSlots);
			}
		}
	}
}

void ULootWidget::Proceed()
{
	manager->SetGameState(EGameState::Map);
	manager->SaveGame();
	manager->LoadLevel();
}
