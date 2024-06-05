#include "CardHandWidget.h"
#include "Components/Overlay.h"
#include "CardWidget.h"

void UCardHandWidget::AddCard(FCardStruct& card)
{
	UCardWidget* Card = Cast<UCardWidget>(CreateWidget(GetWorld(), cardWidget));
	card.widget = Card;
	Card->OnCardClickedEvent.AddDynamic(this, &UCardHandWidget::SelectCard);

	Card->SetupCard(card);

	CardHandOverlay->AddChildToOverlay(card.widget);
	UpdateCardPositions();
}

void UCardHandWidget::RemoveCard(FCardStruct& card)
{
	if (card.widget == nullptr)
	{
		return;
	}
	card.widget->RemoveFromParent();
	card.widget = nullptr;
	UpdateCardPositions();
}

void UCardHandWidget::SelectCard(UCardWidget* Card)
{
	Card->PlayClickAnimation();
}

void UCardHandWidget::UpdateCardPositions()
{
	for (auto* card : CardHandOverlay->GetAllChildren())
	{
		FWidgetTransform position = CalculateCardPosition(card, CardHandOverlay->GetChildIndex(card));
		card->SetRenderTransform(position);
	}
}

FWidgetTransform UCardHandWidget::CalculateCardPosition(UWidget* card, int i)
{
	int count = CardHandOverlay->GetChildrenCount();
	float localIndex = (float)i - (float)(count - 1) / 2;
	localIndex = localIndex < 0 ? localIndex - 0.5 : localIndex;

	float centerPosition = CardHandOverlay->GetDesiredSize().X / 2;

	return FWidgetTransform(FVector2D(100 * roundf(localIndex) + centerPosition, 0), FVector2D(1, 1), FVector2D(0, 0), 0);
}
