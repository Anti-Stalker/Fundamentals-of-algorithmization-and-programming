#include "GameManager.h"

void UGameManager::Init()
{

}

void UGameManager::Initialize(int startHealth, int startEnergy, URelic* startRelic, TArray<UCard*> startingDeck, ECharacterClass characterClass, UTexture2D* characterArt)
{
	maxHealth = startHealth;
	health = maxHealth;
	maxEnergy = startEnergy;
	relics.Add(startRelic);
	for (auto card : startingDeck)
	{
		cards.Add(FCardStruct(card));
	}
	character = characterClass;
	art = characterArt;
}

void UGameManager::EndGame()
{
	gameState = EGameState::Over;
	LoadLevel();
}

void UGameManager::HandleHealth(int change)
{
	health = FMath::Min(health + change, maxHealth);
	OnPlayerStatChangeEvent.Broadcast();

	if (health <= 0)
	{
		EndGame();
	}
}

void UGameManager::HandleMaxHealth(int change)
{
	maxHealth = FMath::Max(maxHealth + change, 0);
	health = FMath::Min(maxHealth, health + change);
	OnPlayerStatChangeEvent.Broadcast();

	if (health <= 0)
	{
		EndGame();
	}
}

void UGameManager::HandleFloor(bool set, int to)
{
	if (set)
	{
		currentFloor = to;
	}
	else
	{
		++currentFloor;
	}
	HandleActiveNodes();
	if (HasRelic("Android"))
	{
		HandleGold(10);
	}
	OnPlayerStatChangeEvent.Broadcast();

	if (currentFloor > 10)
	{
		EndGame();
	}
}

bool UGameManager::HandleGold(int change, bool checkOnly)
{
	if (gold + change >= 0)
	{
		if (!checkOnly)
		{
			gold = FMath::Max(gold + change, 0);
			OnPlayerStatChangeEvent.Broadcast();
		}
		return true;
	}
	return false;
}

void UGameManager::HandleActiveNodes()
{
	if (!map.activeNodes.Num())
	{
		for (auto& node : map.act[0].nodes)
		{
			map.activeNodes.Add(node);
		}
		return;
	}
	map.activeNodes.Empty();
	for (auto& path : map.act[currentFloor - 1].paths)
	{
		if (path.From == currentColumn)
		{
			map.activeNodes.Add(map.act[currentFloor].nodes[path.To]);
		}
	}
}

int UGameManager::GetHealth()
{
	return health;
}

int UGameManager::GetMaxHealth()
{
	return maxHealth;
}

int UGameManager::GetGold()
{
	return gold;
}

int UGameManager::GetFloor()
{
	return currentFloor;
}

int UGameManager::GetMaxEnergy()
{
	return maxEnergy;
}

FMapStruct& UGameManager::GetMap()
{
	return map;
}

TArray<FNodeStruct>& UGameManager::GetActiveNodes()
{
	return map.activeNodes;
}

TArray<FCardStruct>& UGameManager::GetCards()
{
	return cards;
}

TArray<URelic*>& UGameManager::GetRelics()
{
	return relics;
}

TArray<UPotion*>& UGameManager::GetPotions()
{
	return potions;
}

TArray<UEventAsset*>& UGameManager::GetEncounteredEvents()
{
	return encounteredEvents;
}

void UGameManager::AddEncounteredEvent(UEventAsset* event)
{
	encounteredEvents.Add(event);
}

FRandomStream& UGameManager::GetSeed()
{
	return seed;
}

void UGameManager::SetSeed(FRandomStream& newSeed)
{
	seed = newSeed;
}

void UGameManager::SetCurrentColumn(int column)
{
	currentColumn = column;
}

ECharacterClass UGameManager::GetCharacter()
{
	return character;
}

EGameState UGameManager::GetGameState()
{
	return gameState;
}

UTexture2D* UGameManager::GetArt()
{
	return art;
}

void UGameManager::SetArt(UTexture2D* newArt)
{
	art = newArt;
}

void UGameManager::SetGameState(EGameState newGameState)
{
	gameState = newGameState;
}

void UGameManager::AddCard(FCardStruct& card)
{
	cards.Add(card);
}

void UGameManager::RemoveCard(FCardStruct& card)
{
	cards.RemoveAt(cards.Find(card));
}

void UGameManager::AddRelic(URelic* relic)
{
	if (relics.Contains(relic))
	{
		return;
	}
	if (relic->relicName == "Unreal Engine")
	{
		maxEnergy += 1;
	}
	if (relic->relicName == "Unity")
	{
		HandleMaxHealth(10);
	}
	relics.Add(relic);
	OnPlayerStatChangeEvent.Broadcast();
}

bool UGameManager::HasRelic(FString name)
{
	for (auto relic : relics)
	{
		if (relic->relicName == name)
		{
			return true;
		}
	}
	return false;
}

void UGameManager::RemoveRelic(URelic* relic)
{
	relics.RemoveAt(relics.Find(relic));
	OnPlayerStatChangeEvent.Broadcast();
}

bool UGameManager::AddPotion(UPotion* potion)
{
	if (potions.Num() < 3)
	{
		potions.Add(potion);
		OnPlayerStatChangeEvent.Broadcast();
		return true;
	}
	return false;
}

void UGameManager::RemovePotion(UPotion* potion)
{
	potions.RemoveAt(potions.Find(potion));
	OnPlayerStatChangeEvent.Broadcast();
}

void UGameManager::UsePotion()
{
	OnPotionUsedEvent.Broadcast(selectedPotion);
	RemovePotion(selectedPotion);
}

UPotion* UGameManager::GetSelectedPotion()
{
	return selectedPotion;
}

void UGameManager::SetSelectedPotion(UPotion* potion)
{
	selectedPotion = potion;
}

void UGameManager::GenerateMap()
{
	map = FMapStruct();

	GenerateActNodes(map.act);
	GenerateActNodesContent(map.act);
}

void UGameManager::GenerateActNodes(TArray<FFloorStruct>& act)
{
	for (int i = 0; i < 7;)
	{
		int currentNode = seed.RandRange(0, 7);
		if (i == 1 && act[0].nodes[currentNode].type == ENodeType::Mob)
		{
			continue;
		}
		act[0].nodes[currentNode].type = ENodeType::Empty;

		int pathTo = currentNode;
		for (int j = 0; j < 8;)
		{
			pathTo = seed.RandRange((pathTo > 0 ? pathTo - 1 : 0), (pathTo < 8 ? pathTo + 1 : 8));
			if (act[j].paths.Contains(FPathStruct(pathTo, currentNode)))
			{
				continue;
			}

			act[j + 1].nodes[pathTo].type = ENodeType::Empty;
			act[j].paths.Add(FPathStruct(currentNode, pathTo));

			currentNode = pathTo;
			++j;
		}

		act[8].paths.Add(FPathStruct(currentNode, 0));
		++i;
	}
}

void UGameManager::GenerateActNodesContent(TArray<FFloorStruct>& act)
{
	GenerateConstFloor(act, 0, ENodeType::Mob);
	GenerateConstFloor(act, 4, ENodeType::Chest);
	GenerateConstFloor(act, 8, ENodeType::Rest);

	for (int i = 1; i < 8;)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (act[i].nodes[j].type == ENodeType::Empty)
			{
				GenerateNodeContent(act[i].nodes[j]);
			}
		}
		i == 3 ? i += 2 : ++i;
	}

	FixContentGeneration(act);

	act[9].nodes[0].type = ENodeType::Boss;
	act[9].nodes[0].seed = seed.RandRange(INT32_MIN, INT32_MAX);
}

void UGameManager::GenerateConstFloor(TArray<FFloorStruct>& act, int floor, ENodeType type)
{
	for (int i = 0; i < 7; ++i)
	{
		if (act[floor].nodes[i].type == ENodeType::Empty)
		{
			act[floor].nodes[i].type = type;
			act[floor].nodes[i].seed = seed.GetUnsignedInt();
		}
	}
}

bool UGameManager::CheckChainRuleBreak(FNodeStruct& from, FNodeStruct& to)
{
	return (from.type == ENodeType::Elite || from.type == ENodeType::Rest || from.type == ENodeType::Shop) &&
		(to.type == ENodeType::Elite || to.type == ENodeType::Rest || to.type == ENodeType::Shop);
}

void UGameManager::GenerateNodeContent(FNodeStruct& node)
{
	float rand = seed.GetFraction();
	if (rand < 0.45)
	{
		node.type = ENodeType::Mob;
		node.seed = seed.GetUnsignedInt();
	}
	else if (rand < 0.67)
	{
		node.type = ENodeType::Event;
		node.seed = seed.GetUnsignedInt();
	}
	else if (rand < 0.83)
	{
		node.type = ENodeType::Elite;
		node.seed = seed.GetUnsignedInt();
	}
	else if (rand < 0.95)
	{
		node.type = ENodeType::Rest;
	}
	else
	{
		node.type = ENodeType::Shop;
		node.seed = seed.GetUnsignedInt();
	}
}

void UGameManager::FixContentGeneration(TArray<FFloorStruct>& act)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (act[i].nodes[j].type == ENodeType::Elite || act[i].nodes[j].type == ENodeType::Rest)
			{
				GenerateNodeContent(act[i].nodes[j]);
			}
		}
	}

	for (int i = 5; i < 7; ++i)
	{
		for (int j = 5; j < 7; ++j)
		{
			for (auto& path : map.act[i].paths)
			{
				if (CheckChainRuleBreak(act[i].nodes[path.From], act[i + 1].nodes[path.To]))
				{
					GenerateNodeContent(act[i + 1].nodes[path.To]);
				}
			}
		}
	}

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			for (auto& path : map.act[i].paths)
			{
				for (auto& pathTemp : map.act[i].paths)
				{
					if (path.To == pathTemp.To)
					{
						continue;
					}
					while (act[i + 1].nodes[path.To].type == act[i + 1].nodes[pathTemp.To].type)
					{
						GenerateNodeContent(act[i + 1].nodes[pathTemp.To]);
					}
				}
			}
		}
		i == 2 ? i += 2 : ++i;
	}
}

void UGameManager::CreateSaveFile()
{
	UPlayerStats* data = Cast<UPlayerStats>(UGameplayStatics::CreateSaveGameObject(UPlayerStats::StaticClass()));

	UGameplayStatics::SaveGameToSlot(data, "GameSave", 0);
}

void UGameManager::DeleteSaveFile()
{
	UGameplayStatics::DeleteGameInSlot("GameSave", 0);

	seed = 0;
	health = 0;
	maxHealth = 0;
	maxEnergy = 0;
	art = nullptr;
	gold = 0;
	currentFloor = 0;
	character = (ECharacterClass) 0;
	cards.Empty();
	relics.Empty();
	potions.Empty();
	map = FMapStruct();
	gameState = (EGameState) 0;
	encounteredEvents.Empty();
	currentColumn = 0;
}

void UGameManager::SaveGame()
{
	if (!HasSave())
	{
		CreateSaveFile();
		seed.GenerateNewSeed();
		GenerateMap();

		UPlayerStats* data = Cast<UPlayerStats>(UGameplayStatics::CreateSaveGameObject(UPlayerStats::StaticClass()));
		data->seed = seed;
		data->map = map;

		HandleActiveNodes();

		UGameplayStatics::AsyncSaveGameToSlot(data, "GameSave", 0);
		return;
	}

	UPlayerStats* data = Cast<UPlayerStats>(UGameplayStatics::CreateSaveGameObject(UPlayerStats::StaticClass()));

	data->seed = seed;
	data->maxEnergy = maxEnergy;
	data->art = art;
	data->health = health;
	data->maxHealth = maxHealth;
	data->gold = gold;
	data->currentFloor = currentFloor;
	data->character = character;
	data->cards = cards;
	data->relics = relics;
	data->potions = potions;
	data->map = map;
	data->gameState = gameState;
	data->encounteredEvents = encounteredEvents;
	data->currentColumn = currentColumn;

	UGameplayStatics::AsyncSaveGameToSlot(data, "GameSave", 0);
}

void UGameManager::LoadGame()
{
	if (!HasSave())
	{
		return;
	}

	UPlayerStats* data = Cast<UPlayerStats>(UGameplayStatics::LoadGameFromSlot("GameSave", 0));
	if (data == nullptr)
	{
		return;
	}

	seed = data->seed;
	health = data->health;
	maxHealth = data->maxHealth;
	maxEnergy = data->maxEnergy;
	art = data->art;
	gold = data->gold;
	currentFloor = data->currentFloor;
	character = data->character;
	cards = data->cards;
	relics = data->relics;
	potions = data->potions;
	map = data->map;
	gameState = data->gameState;
	encounteredEvents = data->encounteredEvents;
	currentColumn = data->currentColumn;
}

bool UGameManager::HasSave()
{
	return UGameplayStatics::DoesSaveGameExist("GameSave", 0);
}

void UGameManager::LoadLevel()
{
	if (gameState == EGameState::Battle || gameState == EGameState::EliteBattle || gameState == EGameState::BossBattle)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName("Battle"));
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName("Game"));
	}
}