#include "RelicWidget.h"
#include "Components/Image.h"
#include "Relic.h"

void URelicWidget::SetUp(URelic* relic)
{
	Image->SetBrushFromTexture(relic->relicIcon);
	FString des = relic->relicName + "\n" + relic->relicDescription;
	Image->SetToolTipText(FText::FromString(des));
}
