#include "MapWidget.h"
#include <Components/ScrollBox.h>
#include <Components/HorizontalBox.h>
#include "NodeWidget.h"
#include "FloorStruct.h"
#include "Components/Image.h"
#include "GameManager.h"

void UMapWidget::NativeConstruct()
{
	Super::NativeConstruct();

	manager = Cast<UGameManager>(GetGameInstance());
	currentFloors = manager->GetMap().act;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			switch (currentFloors[i].nodes[j].type)
			{
			case ENodeType::Mob:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Regular.Regular")));
				break;
			case ENodeType::Elite:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Elite.Elite")));
				break;
			case ENodeType::Event:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Event.Event")));
				break;
			case ENodeType::Chest:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Treasure.Treasure")));
				break;
			case ENodeType::Shop:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Shop.Shop")));
				break;
			case ENodeType::Rest:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Rest.Rest")));
				break;
			default:
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->SetRenderOpacity(0);
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->SetIsEnabled(false);
				break;
			}
			Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->type = currentFloors[i].nodes[j].type;
			Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(i))->GetChildAt(j))->seed = currentFloors[i].nodes[j].seed;
		}
	}

	Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(9))->GetChildAt(0))->image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("/Game/Textures/Nodes/Boss.Boss")));
	Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(9))->GetChildAt(0))->type = currentFloors[9].nodes[0].type;
	Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(9))->GetChildAt(0))->seed = currentFloors[9].nodes[0].seed;

	int floor = manager->GetFloor();
	if (floor < 9)
	{
		for (int i = 0; i < 7; ++i)
		{
			if (manager->GetActiveNodes().Contains(manager->GetMap().act[floor].nodes[i]))
			{
				Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(floor))->GetChildAt(i))->StartPurge();
			}
		}
	}
	else
	{
		Cast<UNodeWidget>(Cast<UHorizontalBox>(Nodes->GetChildAt(9))->GetChildAt(0))->StartPurge();
	}
}