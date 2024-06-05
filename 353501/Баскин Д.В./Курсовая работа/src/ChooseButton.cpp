#include "ChooseButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UChooseButton::NativeConstruct()
{
	Button->OnClicked.AddDynamic(this, &UChooseButton::ButtonClicked);
}

void UChooseButton::ButtonClicked()
{
	OnChooseButtonClickEvent.Broadcast(this);
}

void UChooseButton::PlayFullSlots()
{
	PlayAnimation(FullSlots);
}

void UChooseButton::SetUp(UTexture2D* icon, FString title, FString description)
{
	if (icon == nullptr)
	{
		Image->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		Image->SetBrushFromTexture(icon);
	}
	Text->SetText(FText::FromString(title));
	Button->SetToolTipText(FText::FromString(description));
}
