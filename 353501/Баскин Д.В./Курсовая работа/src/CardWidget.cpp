#include "CardWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Buff.h"

void UCardWidget::NativeConstruct()
{
	Button->OnClicked.AddDynamic(this, &UCardWidget::Clicked);
}

void UCardWidget::Clicked()
{
	OnCardClickedEvent.Broadcast(this);
}

void UCardWidget::PlayClickAnimation()
{
	PlayAnimation(Selected);
}

void UCardWidget::SetName(FString& name)
{
	CardNameText->SetText(FText::FromString(name));
}

void UCardWidget::SetDescription(FString& description)
{
	CardDescriptionText->SetText(FText::FromString(description));
}

void UCardWidget::SetImage(UTexture2D* image)
{
	CardImage->SetBrushFromTexture(image);
}

void UCardWidget::SetCost(int cost)
{
	CardCostText->SetText(FText::AsNumber(cost));
}

void UCardWidget::SetupCard(FCardStruct& card)
{
	card.widget->SetName(card.cardTitle);

	FString description;

	ECardPlayType playType;
	int effect;
	int repeatCount;
	int cost;
	bool exhaust;
	TArray<UBuff*> buffs;
	if (!card.isUpgraded)
	{
		playType = card.cardPlayType;
		effect = card.cardEffect;
		repeatCount = card.repeatCount;
		cost = card.cardCost;
		exhaust = card.exhaust;
		buffs = card.cardBuffs;
	}
	else
	{
		playType = card.uCardPlayType;
		effect = card.uCardEffect;
		repeatCount = card.uRepeatCount;
		cost = card.uCardCost;
		exhaust = card.uExhaust;
		buffs = card.uCardBuffs;
	}

	card.widget->SetCost(cost);

	switch (card.cardPlayType)
	{
	case ECardPlayType::Ethereal:
		description += "Ethereal.\n";
		break;
	case ECardPlayType::Retain:
		description += "Retain.\n";
		break;
	default:
		break;
	}

	switch (card.cardType)
	{
	case ECardType::Curse:
		description += "Curse.\n";
		break;
	case ECardType::Power:
		description += "Power.\n";
		break;
	case ECardType::Status:
		description += "Status.\n";
		break;
	case ECardType::Attack:
		description += "Deal ";
		description.AppendInt(effect);
		description += (repeatCount > 1 ? "x" + FString::FromInt(repeatCount) : "");
		description += " damage";
		description += (card.cardTargetType == ECardTargetType::AllEnemies ? " to all enemies" : "");
		description += (card.cardTargetType == ECardTargetType::RandomEnemy ? " to random enemy(s)" : "");
		description += ".\n";
		break;
	case ECardType::Skill:
		if (card.cardEffect == 0)
		{
			break;
		}
		description += "Gain ";
		description.AppendInt(effect);
		description += " block.\n";
		break;
	default:
		break;
	}

	for (auto& buff : buffs)
	{
		description += (buff->applyToSelf ? "Gain " : "Apply ");
		description.AppendInt(buff->amount);
		description += " ";
		description += buff->name;
		description += (buff->applyToSelf ? "\n" : " to enemy.\n");
	}

	description += (exhaust ? "Exhaust." : "");

	card.widget->SetDescription(description);
	card.widget->SetImage(card.cardIcon);
}
