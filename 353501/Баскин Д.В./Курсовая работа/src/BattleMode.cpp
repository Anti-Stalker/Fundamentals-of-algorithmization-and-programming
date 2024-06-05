#include "BattleMode.h"
#include "BattleWidget.h"
#include "GameManager.h"
#include "CardWidget.h"
#include "Components/Button.h"
#include "Buff.h"
#include "Enemy.h"
#include "FighterWidget.h"
#include "LootWidget.h"

void ABattleMode::BeginPlay()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	controller->SetShowMouseCursor(true);
	manager = Cast<UGameManager>(GetGameInstance());
	battleWidget = Cast<UBattleWidget>(CreateWidget(GetWorld(), bwidget));
	battleWidget->AddToViewport(0);
	battleWidget->OnEndTurnClickedEvent.AddDynamic(this, &ABattleMode::HandleTurn);
	manager->OnPotionUsedEvent.AddDynamic(this, &ABattleMode::PotionUse);

	UUserWidget* hud = CreateWidget(GetWorld(), hudWidget);
	hud->AddToViewport(9);

	TArray<UEnemy*> enemyPull;
	switch (manager->GetGameState())
	{
	case EGameState::Battle:
		enemyPull = possibleActEnemies;
		break;
	case EGameState::EliteBattle:
		enemyPull = possibleActEliteEnemies;
		break;
	case EGameState::BossBattle:
		enemyPull = bosses;
		break;
	}
	for (size_t i = 0; i < (manager->GetGameState() == EGameState::Battle ? manager->GetSeed().RandRange(1, 2) : 1); ++i)
	{
		UEnemy* enemy = enemyPull[manager->GetSeed().RandRange(0, enemyPull.Num() - 1)];
		InitEnemy(enemy);
	}
	InitPlayer();

	manager->OnPlayerStatChangeEvent.AddDynamic(this, &ABattleMode::UpdatePlayerFighter);

	HandleTurn();
}

void ABattleMode::InitPlayer()
{
	TArray<FBuffStruct> playerStartBuffs;
	playerFighter = FFighterStruct(manager->GetHealth(), manager->GetMaxHealth(), 0, playerStartBuffs, manager->GetArt(), true);
	UFighterWidget* Fighter = battleWidget->AddFighter(playerFighter);
	Fighter->OnFighterClickedEvent.AddDynamic(this, &ABattleMode::SelectFighter);

	deckSeed = manager->GetSeed().GetUnsignedInt();
	randomSeed = manager->GetSeed().GetUnsignedInt();
	TArray<FCardStruct> temp;
	for (int i = 0; i < manager->GetCards().Num(); ++i)
	{
		temp.Add(manager->GetCards()[i]);
	}
	int n = temp.Num();
	for (int i = 0; i < n; ++i)
	{
		int rand = deckSeed.RandRange(0, temp.Num() - 1);
		drawPile.Add(temp[rand]);
		temp.RemoveAt(rand);
	}

	for (auto relic : manager->GetRelics())
	{
		if (relic->relicBuff != nullptr)
		{
			FBuffStruct buff = FBuffStruct(relic->relicBuff);
			ApplyBuff(playerFighter, buff);
		}
	}
}

void ABattleMode::InitEnemy(UEnemy* enemy)
{
	TArray<FBuffStruct> enemyStartBuffs(enemy->startBuffs);
	int i = enemyFighters.Add(FFighterStruct(enemy->health, enemy->maxHealth, 0, enemyStartBuffs, enemy->art));
	enemyFighters[i].seed = manager->GetSeed().GetUnsignedInt();
	enemyFighters[i].possibleActions = enemy->possibleMoves;
	GenerateNextIntent(enemyFighters[i]);
	UFighterWidget* Fighter = battleWidget->AddFighter(enemyFighters[i]);
	Fighter->OnFighterClickedEvent.AddDynamic(this, &ABattleMode::SelectFighter);
}

void ABattleMode::GenerateNextIntent(FFighterStruct& enemy)
{
	TArray<UEnemyAction*> temp;
	for (auto& action : enemy.possibleActions)
	{
		for (int i = 0; i < action->chance; ++i)
		{
			temp.Add(action);
		}
	}
	enemy.intent = temp[enemy.seed.RandRange(0, temp.Num() - 1)];
}

void ABattleMode::RemoveEnemy(FFighterStruct& enemy)
{
	battleWidget->RemoveFighter(enemy);
	enemyFighters.RemoveAt(enemyFighters.Find(enemy));

	if (!enemyFighters.Num())
	{
		EndFight();
	}
}

void ABattleMode::UpdatePlayerFighter()
{
	playerFighter.currentHealth = manager->GetHealth();
	playerFighter.maxHealth = manager->GetMaxHealth();
	battleWidget->UpdateFighter(playerFighter);
}

void ABattleMode::HandleTurn()
{
	if (turn == ETurn::Player)
	{
		selectedCard = nullptr;

		if (manager->HasRelic("Windows") && !playerFighter.currentBlock)
		{
			ApplyBlock(playerFighter, 4);
		}
		turn = ETurn::Enemies;
		battleWidget->EndTurnButton->SetIsEnabled(false);

		for (int i = cardsInHand.Num() - 1; i >= 0; --i)
		{
			switch (cardsInHand[i].cardPlayType)
			{
			case ECardPlayType::Regular:
				DiscardCard(cardsInHand[i]);
				break;
			case ECardPlayType::Ethereal:
				ExhaustCard(cardsInHand[i]);
				break;
			default:
				break;
			}
		}

		for (auto& enemy : enemyFighters)
		{
			enemy.currentBlock = 0;
			ReduceBuffs(enemy);
			battleWidget->UpdateFighter(enemy);
		}

		for (auto& enemy : enemyFighters)
		{
			PerformEnemyIntent(enemy);
			battleWidget->UpdateFighter(enemy);
		}

		HandleTurn();
	}
	else
	{
		turn = ETurn::Player;

		ReduceBuffs(playerFighter);

		for (auto& enemy : enemyFighters)
		{
			battleWidget->UpdateFighter(enemy);
		}
		if (!manager->HasRelic("C#"))
		{
			playerFighter.currentBlock = 0;
			battleWidget->UpdateFighter(playerFighter);
		}

		UseEnergy(-manager->GetMaxEnergy());

		for (int i = 0; i < drawAmount; ++i)
		{
			DrawCard();
		}

		battleWidget->EndTurnButton->SetIsEnabled(true);
	}
}

void ABattleMode::SelectCard(UCardWidget* Card)
{
	for (auto& card : cardsInHand)
	{
		if (card.widget == Card)
		{
			switch (card.cardTargetType)
			{
			case ECardTargetType::Self:
				playerFighter.widget->PlaySelfIndicator();
				break;
			default:
				for (auto& fighter : enemyFighters)
				{
					fighter.widget->PlayAttackIndicator();
				}
				break;
			}
		}
	}
	selectedCard = Card;
}

void ABattleMode::SelectFighter(UFighterWidget* Fighter)
{
	if (selectedCard == nullptr)
	{
		return;
	}

	FCardStruct card;
	for (auto& c : cardsInHand)
	{
		if (c.widget == selectedCard)
		{
			card = c;
			break;
		}
	}

	FFighterStruct& fighter = FindFighter(Fighter);
	if ((card.cardTargetType == ECardTargetType::Self && fighter.isPlayer) ||
		(card.cardTargetType != ECardTargetType::Self && !fighter.isPlayer) ||
		(card.cardType != ECardType::Attack && card.cardType != ECardType::Skill))
	{
		PlayCard(card, fighter);
	}
}

void ABattleMode::PlayCard(FCardStruct& card, FFighterStruct& fighter)
{
	bool isUpgraded = card.isUpgraded;
	int cost = (isUpgraded ? card.uCardCost : card.cardCost);

	if (energy < cost)
	{
		battleWidget->PlayNotEnoughEnergy();
		return;
	}
	if (card.cardType == ECardType::Curse || card.cardType == ECardType::Status)
	{
		selectedCard = nullptr;
		return;
	}

	TArray<UBuff*> Buffs = (isUpgraded ? card.uCardBuffs : card.cardBuffs);
	TArray<FBuffStruct> buffs;
	for (auto buff : Buffs)
	{
		buffs.Add(buff);
	}

	if (card.cardType == ECardType::Power)
	{
		for (auto& buff : buffs)
		{
			ApplyBuff(playerFighter, buff);
		}
	}

	int effect = (isUpgraded ? card.uCardEffect : card.cardEffect);
	int repeatCount = (isUpgraded ? card.uRepeatCount : card.repeatCount);
	CardBuffs(card, buffs, fighter, repeatCount);
	CardEffect(card, fighter, effect, repeatCount);

	bool exhaust = (isUpgraded ? card.uExhaust : card.exhaust);
	if (exhaust)
	{
		ExhaustCard(card);
	}
	else
	{
		DiscardCard(card);
	}
	UseEnergy(cost);
	selectedCard = nullptr;
}

void ABattleMode::CardBuffs(FCardStruct& card, TArray<FBuffStruct>& buffs, FFighterStruct& fighter, int repeatCount)
{
	for (int i = 0; i < repeatCount; ++i)
	{
		for (auto& buff : buffs)
		{
			switch (card.cardTargetType)
			{
			case ECardTargetType::RandomEnemy:
				ApplyBuff(enemyFighters[randomSeed.RandRange(0, enemyFighters.Num() - 1)], buff);
				break;
			case ECardTargetType::AllEnemies:
				for (auto& enemy : enemyFighters)
				{
					ApplyBuff(enemy, buff);
				}
				break;
			default:
				ApplyBuff(fighter, buff);
				break;
			}
		}
	}
}

void ABattleMode::CardEffect(FCardStruct& card, FFighterStruct& fighter, int effect, int repeatCount)
{
	if (effect)
	{
		if (card.cardType == ECardType::Skill)
		{
			playerFighter.widget->PlayBlockAnimation();
			ApplyBlock(playerFighter, effect);
		}
		else
		{
			for (int i = 0; i < repeatCount; ++i)
			{
				switch (card.cardTargetType)
				{
				case ECardTargetType::AllEnemies:
					for (auto& enemy : enemyFighters)
					{
						ApplyDamage(playerFighter, enemy, effect);
					}
					break;
				case ECardTargetType::Enemy:
					ApplyDamage(playerFighter, fighter, effect);
					break;
				case ECardTargetType::RandomEnemy:
					ApplyDamage(playerFighter, enemyFighters[randomSeed.RandRange(0, enemyFighters.Num() - 1)], effect);
				default:
					break;
				}
			}
		}
	}
}

void ABattleMode::DiscardCard(FCardStruct& card)
{
	discardPile.Add(card);
	cardsInHand.RemoveAt(cardsInHand.Find(card));
	battleWidget->RemoveCardFromHand(card);
	battleWidget->UpdateDiscardNumber(discardPile.Num());
}

void ABattleMode::ExhaustCard(FCardStruct& card)
{
	exhaustPile.Add(card);
	cardsInHand.RemoveAt(cardsInHand.Find(card));
	battleWidget->RemoveCardFromHand(card);
	battleWidget->UpdateExhaustNumber(exhaustPile.Num());
}

void ABattleMode::DrawCard()
{
	if (cardsInHand.Num() > 12)
	{
		return;
	}
	if (!drawPile.Num())
	{
		ShuffleDiscardToDraw();
	}
	if (drawPile.Num())
	{
		cardsInHand.Add(drawPile.Pop());
		UCardWidget* cardWidget = battleWidget->AddCardToHand(cardsInHand.Last());
		cardWidget->OnCardClickedEvent.AddDynamic(this, &ABattleMode::SelectCard);
		battleWidget->UpdateDrawNumber(drawPile.Num());
	}
}

void ABattleMode::ShuffleDiscardToDraw()
{
	int n = discardPile.Num();
	for (int i = 0; i < n; ++i)
	{
		discardPile.Swap(deckSeed.RandRange(0, n - 1), deckSeed.RandRange(0, n - 1));
	}
	Swap(drawPile, discardPile);
	battleWidget->UpdateDrawNumber(drawPile.Num());
	battleWidget->UpdateDrawNumber(discardPile.Num());
}

void ABattleMode::PerformEnemyIntent(FFighterStruct& enemy)
{
	if (enemy.intent->actionType == EActionType::Attack)
	{
		enemy.widget->PlayAttackAnimation();
		int damage = enemy.intent->amount;
		ApplyDamage(enemy, playerFighter, damage);
	}
	else if (enemy.intent->actionType == EActionType::Block)
	{
		enemy.widget->PlayBlockAnimation();
		int block = enemy.intent->amount;
		ApplyBlock(enemy, block);
	}

	if (enemy.intent->buff != nullptr)
	{
		FBuffStruct buff = FBuffStruct(enemy.intent->buff);
		FFighterStruct& fighter = (enemy.intent->buff->applyToSelf ? enemy : playerFighter);
		ApplyBuff(fighter, buff);
	}
	GenerateNextIntent(enemy);
	battleWidget->UpdateFighter(enemy);
}

void ABattleMode::ApplyBuff(FFighterStruct& fighter, FBuffStruct& buff)
{
	int buffIndex = -1;
	for (int i = 0; i < fighter.buffs.Num(); ++i)
	{
		if (fighter.buffs[i].name == buff.name)
		{
			buffIndex = i;
			break;
		}
	}
	if (buffIndex == -1)
	{
		fighter.buffs.Add(FBuffStruct(buff));
	}
	else
	{
		fighter.buffs[buffIndex].amount += buff.amount;
	}
	battleWidget->UpdateFighter(fighter);
}

void ABattleMode::ApplyDamage(FFighterStruct attacker, FFighterStruct& defender, int amount, bool passive)
{
	int damage;
	if (!passive)
	{
		for (auto& buff : attacker.buffs)
		{
			if (buff.name == "Strength")
			{
				amount *= (attacker.isPlayer && manager->HasRelic("Approaching Deadline") ? 1.5 : 1.25);
			}
		}
		for (auto& buff : defender.buffs)
		{
			if (buff.name == "Vulnerable")
			{
				amount *= (!defender.isPlayer && manager->HasRelic("QT") ? 1.5 : 1.25);
			}
		}
		damage = -FMath::Min(defender.currentBlock - amount, 0);
		defender.currentBlock = FMath::Max(0, defender.currentBlock - amount);
	}
	else
	{
		damage = amount;
	}

	if (damage && (!defender.currentBlock || passive))
	{
		if (defender.isPlayer)
		{
			if (damage < 5 && manager->HasRelic("Linux"))
			{
				damage = 1;
			}
			manager->HandleHealth(-damage);
		}
		else
		{
			defender.currentHealth -= damage;
			if (defender.currentHealth <= 0)
			{
				RemoveEnemy(defender);
				return;
			}
		}
		if (defender.widget != nullptr)
		{
			defender.widget->PlayDamageReceiveAnimation();
		}
	}
	if (defender.widget != nullptr)
	{
		battleWidget->UpdateFighter(defender);
	}
}

void ABattleMode::ApplyBlock(FFighterStruct& fighter, int amount)
{
	fighter.currentBlock += amount;
	battleWidget->UpdateFighter(fighter);
}

void ABattleMode::ReduceBuffs(FFighterStruct& fighter)
{
	for (int i = 0; i < fighter.buffs.Num(); ++i)
	{
		if (fighter.buffs[i].name == "Regeneration")
		{
			ApplyDamage(FFighterStruct(), fighter, -fighter.buffs[i].amount, true);
		}
		if (fighter.buffs[i].name == "Poison")
		{
			ApplyDamage(FFighterStruct(), fighter, fighter.buffs[i].amount, true);
		}
		--fighter.buffs[i].amount;
		if (fighter.buffs[i].amount <= 0)
		{
			fighter.buffs.RemoveAt(i);
		}
	}
}

void ABattleMode::UseEnergy(int amount)
{
	energy -= amount;
	battleWidget->UpdateEnergyNumber(energy);
}

void ABattleMode::PotionUse(UPotion* potion)
{
	if (potion->name == "MaxHP Potion")
	{
		manager->HandleMaxHealth(5);
	}
	else if (potion->name == "Heal Potion")
	{
		manager->HandleHealth(15 / (double)100 * manager->GetMaxHealth());
	}
	else if (potion->name == "Block Potion")
	{
		ApplyBlock(playerFighter, 12);
	}
	else
	{
		FBuffStruct buff = FBuffStruct(potion->buff);
		ApplyBuff(playerFighter, buff);
	}
}

FFighterStruct& ABattleMode::FindFighter(UFighterWidget* Fighter)
{
	for (auto& fighter : enemyFighters)
	{
		if (fighter.widget == Fighter)
		{
			return fighter;
		}
	}
	return playerFighter;
}

void ABattleMode::EndFight()
{
	if (manager->GetGameState() == EGameState::BossBattle)
	{
		manager->EndGame();
	}
	if (manager->HasRelic("Vadimka"))
	{
		manager->HandleHealth(manager->GetMaxHealth() / 10);
	}

	ULootWidget* widget = Cast<ULootWidget>(CreateWidget(GetWorld(), lootWidget));
	widget->AddToViewport(5);
}