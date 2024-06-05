#include "NodeWidget.h"
#include "GameManager.h"
#include "Components/Button.h"
#include "Components/Image.h"

void UNodeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	button->OnClicked.AddDynamic(this, &UNodeWidget::LoadNodeContent);
}

void UNodeWidget::LoadNodeContent()
{
	UGameManager* manager = Cast<UGameManager>(GetGameInstance());

	int floor = this->GetParent()->GetParent()->GetChildIndex(this->GetParent());
	int column = this->GetParent()->GetChildIndex(this);
	FNodeStruct& node = manager->GetMap().act[floor].nodes[column];
	if (!manager->GetActiveNodes().Contains(node))
	{
		return;
	}

	switch (type)
	{
	case ENodeType::Mob:
		manager->SetGameState(EGameState::Battle);
		break;
	case ENodeType::Elite:
		manager->SetGameState(EGameState::EliteBattle);
		break;
	case ENodeType::Event:
		manager->SetGameState(EGameState::Event);
		break;
	case ENodeType::Chest:
		manager->SetGameState(EGameState::TreasureRoom);
		break;
	case ENodeType::Shop:
		manager->SetGameState(EGameState::Shop);
		break;
	case ENodeType::Rest:
		manager->SetGameState(EGameState::RestSide);
		break;
	case ENodeType::Boss:
		manager->SetGameState(EGameState::BossBattle);
		break;
	default:
		break;
	}
	manager->SetSeed(seed);

	manager->SetCurrentColumn(column);
	manager->HandleFloor();
	manager->SaveGame();
	manager->LoadLevel();
}

void UNodeWidget::StartPurge()
{
	PlayAnimation(Purge, 0 , 0);
}
