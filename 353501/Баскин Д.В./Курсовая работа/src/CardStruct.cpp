#include "CardStruct.h"
#include "CardWidget.h"

FCardStruct::FCardStruct(UCard* card, bool upgraded)
{
	cardTitle = card->cardTitle;
	cardRarity = card->cardRarity;
	isUpgraded = upgraded;
	exhaust = card->exhaust;
	uExhaust = card->uExhaust;
	cardCost = card->cardCost;
	cardEffect = card->cardEffect;
	cardBuffs = card->cardBuffs;
	repeatCount = card->repeatCount;
	uCardCost = card->uCardCost;
	uCardEffect = card->uCardEffect;
	uCardBuffs = card->uCardBuffs;
	uRepeatCount = card->uRepeatCount;
	cardIcon = card->cardIcon;
	cardType = card->cardType;
	cardClass = card->cardClass;
	cardPlayType = card->cardPlayType;
	uCardPlayType = card->uCardPlayType;
	cardTargetType = card->cardTargetType;
	widget = nullptr;
}

bool FCardStruct::operator==(const FCardStruct& other) const
{
	if (!(cardTitle == other.cardTitle &&
		cardRarity == other.cardRarity &&
		isUpgraded == other.isUpgraded &&
		exhaust == other.exhaust &&
		uExhaust == other.uExhaust &&
		cardCost == other.cardCost &&
		cardEffect == other.cardEffect &&
		cardBuffs == other.cardBuffs &&
		repeatCount == other.repeatCount &&
		uCardCost == other.uCardCost &&
		uCardEffect == other.uCardEffect &&
		uCardBuffs == other.uCardBuffs &&
		uRepeatCount == other.uRepeatCount &&
		cardIcon == other.cardIcon &&
		cardType == other.cardType &&
		cardClass == other.cardClass &&
		cardPlayType == other.cardPlayType &&
		uCardPlayType == other.uCardPlayType &&
		cardTargetType == other.cardTargetType &&
		widget == other.widget))
	{
		return false;
	}

	return true;
}
