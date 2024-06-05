#include "ShopWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/ScaleBox.h"
#include "GameManager.h"
#include "Relic.h"
#include "CardSelectionWidget.h"
#include "CardWidget.h"
#include "Components/TextBlock.h"
#include "Components/Overlay.h"

void UShopWidget::NativeConstruct()
{
	manager = Cast<UGameManager>(GetGameInstance());
	seed = manager->GetSeed();

	GenerateContent();
	
	Button->OnClicked.AddDynamic(this, &UShopWidget::Select0);
	Card1->OnClicked.AddDynamic(this, &UShopWidget::Select1);
	Card2->OnClicked.AddDynamic(this, &UShopWidget::Select2);
	Card3->OnClicked.AddDynamic(this, &UShopWidget::Select3);
	Relic1->OnClicked.AddDynamic(this, &UShopWidget::Select4);
	Relic2->OnClicked.AddDynamic(this, &UShopWidget::Select5);
	CardRemove->OnClicked.AddDynamic(this, &UShopWidget::Select6);
	Proceed->OnClicked.AddDynamic(this, &UShopWidget::Confirm);

	cardSelection = Cast<UCardSelectionWidget>(CreateWidget(GetWorld(), cardSelectionWidget));
	cardSelection->OnCardSelectConfirmClickedEvent.AddDynamic(this, &UShopWidget::CardRemoval);
	CardSelectionBox->AddChild(cardSelection);
	cardSelection->SetVisibility(ESlateVisibility::Hidden);
}

void UShopWidget::GenerateContent()
{
	switch (manager->GetCharacter())
	{
	case ECharacterClass::ComputerScienceChad:
		cards.Add(cardsCSC[seed.RandRange(0, cardsCSC.Num() - 1)]);
		cards.Add(cardsCSC[seed.RandRange(0, cardsCSC.Num() - 1)]);
		break;
	case ECharacterClass::GomelStateRegionalLyceumEnjoyer:
		cards.Add(cardsGSRLE[seed.RandRange(0, cardsGSRLE.Num() - 1)]);
		cards.Add(cardsGSRLE[seed.RandRange(0, cardsGSRLE.Num() - 1)]);
		break;
	default:
		break;
	}
	cards.Add(cardsColorless[seed.RandRange(0, cardsColorless.Num() - 1)]);
	relics.Add(relicsPull[seed.RandRange(0, relicsPull.Num() - 1)]);
	int noRepeat;
	do
	{
		noRepeat = seed.RandRange(0, relicsPull.Num() - 1);
	} while (relics[0] == relicsPull[noRepeat]);
	relics.Add(relicsPull[noRepeat]);
	for (int i = 0; i < 5; ++i)
	{
		cost.Add(seed.RandRange(-150, -35));
	}
	Price1->SetText(FText::AsNumber(-cost[0]));
	Price2->SetText(FText::AsNumber(-cost[1]));
	Price3->SetText(FText::AsNumber(-cost[2]));
	Price4->SetText(FText::AsNumber(-cost[3]));
	Price5->SetText(FText::AsNumber(-cost[4]));

	UCardWidget* Card1Widget = Cast<UCardWidget>(CreateWidget(GetWorld(), cardWidget));
	cards[0].widget = Card1Widget;
	Card1Widget->SetupCard(cards[0]);
	UCardWidget* Card2Widget = Cast<UCardWidget>(CreateWidget(GetWorld(), cardWidget));
	cards[1].widget = Card2Widget;
	Card2Widget->SetupCard(cards[1]);
	UCardWidget* Card3Widget = Cast<UCardWidget>(CreateWidget(GetWorld(), cardWidget));
	cards[2].widget = Card3Widget;
	Card3Widget->SetupCard(cards[2]);
	Card1O->AddChildToOverlay(Card1Widget);
	Card2O->AddChildToOverlay(Card2Widget);
	Card3O->AddChildToOverlay(Card3Widget);
	Relic1Image->SetBrushFromTexture(relics[0]->relicIcon);
	Relic2Image->SetBrushFromTexture(relics[1]->relicIcon);
}

void UShopWidget::Select0()
{
	selection = 0;
}

void UShopWidget::Select1()
{
	selection = 1;
}

void UShopWidget::Select2()
{
	selection = 2;
}

void UShopWidget::Select3()
{
	selection = 3;
}

void UShopWidget::Select4()
{
	selection = 4;
}

void UShopWidget::Select5()
{
	selection = 5;
}

void UShopWidget::Select6()
{
	selection = 6;
}

void UShopWidget::CardRemoval(FCardStruct& card)
{
	if (manager->HandleGold(-75))
	{
		card.widget = nullptr;
		manager->RemoveCard(card);
	}
}

void UShopWidget::Confirm()
{
	switch (selection)
	{
	case 0:
		manager->SetGameState(EGameState::Map);
		manager->SaveGame();
		manager->LoadLevel();
		break;
	case 1:
		if (manager->HandleGold(cost[0]))
		{
			manager->AddCard(cards[0]);
			Card1->RemoveFromParent();
			selection = 0;
			manager->SaveGame();
		}
		break;
	case 2:
		if (manager->HandleGold(cost[1]))
		{
			manager->AddCard(cards[1]);
			Card2->RemoveFromParent();
			selection = 0;
			manager->SaveGame();
		}
		break;
	case 3:
		if (manager->HandleGold(cost[2]))
		{
			manager->AddCard(cards[2]);
			Card3->RemoveFromParent();
			selection = 0;
			manager->SaveGame();
		}
		break;
	case 4:
		if (manager->HandleGold(cost[3]))
		{
			manager->AddRelic(relics[0]);
			Relic1->RemoveFromParent();
			selection = 0;
			manager->SaveGame();
		}
		break;
	case 5:
		if (manager->HandleGold(cost[4]))
		{
			manager->AddRelic(relics[1]);
			Relic2->RemoveFromParent();
			selection = 0;
			manager->SaveGame();
		}
		break;
	case 6:
		if (manager->HandleGold(75, true))
		{
			cardSelection->SetVisibility(ESlateVisibility::Visible);
		}
		break;
	default:
		break;
	}
}
