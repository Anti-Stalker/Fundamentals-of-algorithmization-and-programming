#include "FighterStruct.h"
#include "Buff.h"
#include "FighterWidget.h"
#include "EnemyAction.h"

FFighterStruct::FFighterStruct(int health, int maxHealth, int block, TArray<FBuffStruct> buffs, UTexture2D* visuals, bool isPlayer)
{
	this->currentHealth = health;
	this->maxHealth = maxHealth;
	this->currentBlock = block;
	this->buffs = buffs;
	this->visuals = visuals;
	this->isPlayer = isPlayer;
	this->intent = nullptr;
}

bool FFighterStruct::operator==(const FFighterStruct& other) const
{
	if (currentHealth == other.currentHealth &&
		currentBlock == other.currentBlock &&
		maxHealth == other.maxHealth &&
		buffs == other.buffs &&
		visuals == other.visuals &&
		isPlayer == other.isPlayer &&
		intent == other.intent &&
		widget == other.widget &&
		possibleActions == other.possibleActions &&
		seed.GetCurrentSeed() == other.seed.GetCurrentSeed())
	{
		return true;
	}
	return false;
}
