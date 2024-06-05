#include "PlayerStatsWidget.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "RelicWidget.h"
#include "PotionWidget.h"
#include "GameManager.h"
#include "Components/Button.h"

void UPlayerStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	manager = Cast<UGameManager>(GetGameInstance());
	manager->OnPlayerStatChangeEvent.AddDynamic(this, &UPlayerStatsWidget::UpdateInfo);

	ToMenu->OnClicked.AddDynamic(this, &UPlayerStatsWidget::Menu);

	UpdateInfo();
}

void UPlayerStatsWidget::UpdateInfo()
{
	switch (manager->GetCharacter())
	{
	case ECharacterClass::ComputerScienceChad:
		ClassText->SetText(FText::FromString("CSC Chad"));
		break;
	case ECharacterClass::GomelStateRegionalLyceumEnjoyer:
		ClassText->SetText(FText::FromString("GSRL Enjoyer"));
		break;
	}
	
	HPText->SetText(FText::Format(FText::FromString(TEXT("{0}/{1} HP")), FText::AsNumber(manager->GetHealth()), FText::AsNumber(manager->GetMaxHealth())));
	GoldText->SetText(FText::Format(FText::FromString(TEXT("{0} Gold")), FText::AsNumber(manager->GetGold())));
	FloorText->SetText(FText::Format(FText::FromString(TEXT("Floor #{0}")), FText::AsNumber(manager->GetFloor())));

	RelicsBox->ClearChildren();
	for (auto& relic : manager->GetRelics())
	{
		URelicWidget* Relic = Cast<URelicWidget>(CreateWidget(GetWorld(), relicWidget));
		Relic->SetUp(relic);
		RelicsBox->AddChildToHorizontalBox(Relic);
	}

	PotionsBox->ClearChildren();
	for (auto& potion : manager->GetPotions())
	{
		UPotionWidget* Potion = Cast<UPotionWidget>(CreateWidget(GetWorld(), potionWidget));
		Potion->SetUp(potion);
		PotionsBox->AddChildToHorizontalBox(Potion);
	}
}

void UPlayerStatsWidget::Menu()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
}
