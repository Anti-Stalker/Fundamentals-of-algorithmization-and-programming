#include "EventWidget.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "GameManager.h"
#include "ChooseButton.h"
#include "EventAsset.h"

void UEventWidget::NativeConstruct()
{
	manager = Cast<UGameManager>(GetGameInstance());
	seed = manager->GetSeed();

	Proceed->OnClicked.AddDynamic(this, &UEventWidget::Continue);

	do
	{
		event = events[seed.RandRange(0, events.Num() - 1)];
	} while (manager->GetEncounteredEvents().Contains(event));

	manager->AddEncounteredEvent(event);

	Image->SetBrushFromTexture(event->image);
	Text->SetText(FText::FromString(event->text));
	for (int i = 0; i < event->options.Num(); ++i)
	{
		UChooseButton* optionButton = CreateButton();
		if (event->options[i] == nullptr)
		{
			optionButton->SetUp(nullptr, "[Leave]", "");
			continue;
		}
		FString tooltip = GenerateTooltip(i);
		optionButton->SetUp(nullptr, event->options[i]->text, tooltip);
		if (!manager->HandleGold(event->options[i]->goldChange, true))
		{
			optionButton->SetIsEnabled(false);
		}
	}
}

UChooseButton* UEventWidget::CreateButton()
{
	UChooseButton* newLootButton = Cast<UChooseButton>(CreateWidget(GetWorld(), chooseButtonWidget));
	OptionsBox->AddChildToVerticalBox(newLootButton);
	newLootButton->OnChooseButtonClickEvent.AddDynamic(this, &UEventWidget::ChooseOption);
	return newLootButton;
}

FString UEventWidget::GenerateTooltip(int index)
{
	FString tooltip;
	UEventOption* option = event->options[index];
	if (option == nullptr)
	{
		return "";
	}
	
	if (option->healthChange)
	{
		if (option->maxHealth)
		{
			tooltip += (option->healthChange > 0 ? "Gain " : "Lose ");
			tooltip.AppendInt(option->healthChange);
			tooltip += (option->healthPercentage ? "% Max HP;\n" : " Max HP;\n");
		}
		else
		{
			tooltip += (option->healthChange > 0 ? "Gain " : "Lose ");
			tooltip.AppendInt(option->healthChange);
			tooltip += (option->healthPercentage ? "% HP;\n" : " HP;\n");
		}
	}
	if (option->goldChange)
	{
		tooltip += (option->goldChange > 0 ? "Receive " : "Lose ");
		tooltip.AppendInt(option->goldChange);
		tooltip += " Gold;\n";
	}
	if (option->relicToObtain)
	{
		tooltip += "Get ";
		tooltip += option->relicToObtain->relicName;
		tooltip += " Relic;\n";
	}
	if (option->curseToObtain)
	{
		tooltip += "Curse: ";
		tooltip += option->relicToObtain->relicName;
		tooltip += ";";
	}

	return tooltip;
}

void UEventWidget::ChooseOption(UChooseButton* optionButton)
{
	int index = OptionsBox->GetChildIndex(optionButton);
	UEventOption* option = event->options[index];

	if (option == nullptr)
	{
		Continue();
	}

	Text->SetText(FText::FromString(option->afterText));
	OptionsBox->RemoveFromParent();
	if (option->healthChange)
	{
		if (option->maxHealth)
		{
			option->healthPercentage ? manager->HandleMaxHealth(option->healthChange / (double)100 * manager->GetMaxHealth()) : manager->HandleMaxHealth(option->healthChange);
		}
		else
		{
			option->healthPercentage ? manager->HandleHealth(option->healthChange / (double)100 * manager->GetMaxHealth()) : manager->HandleHealth(option->healthChange);
		}
	}
	if (option->goldChange)
	{
		manager->HandleGold(option->goldChange);
	}
	if (option->curseToObtain)
	{
		FCardStruct card = FCardStruct(option->curseToObtain);
		manager->AddCard(card);
	}
	if (option->relicToObtain)
	{
		manager->AddRelic(option->relicToObtain);
	}

	Proceed->SetVisibility(ESlateVisibility::Visible);
}

void UEventWidget::Continue()
{
	manager->SetGameState(EGameState::Map);
	manager->SaveGame();
	manager->LoadLevel();
}
