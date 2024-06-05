#include "PotionWidget.h"
#include "Components/Image.h"
#include "Components/MenuAnchor.h"
#include "Components/Button.h"
#include "Potion.h"
#include "PotionDropdownWidget.h"
#include "GameManager.h"

void UPotionWidget::NativeConstruct()
{
	Button->OnClicked.AddDynamic(this, &UPotionWidget::OpenMenu);
}

void UPotionWidget::OpenMenu()
{
	Menu->ToggleOpen(true);
	UGameManager* manager = Cast<UGameManager>(GetGameInstance());
	manager->SetSelectedPotion(potion);
}

void UPotionWidget::SetUp(UPotion* ref)
{
	Image->SetBrushFromTexture(ref->icon);
	FString des = ref->name + "\n" + ref->description;
	Button->SetToolTipText(FText::FromString(des));
	potion = ref;
}
