#include "BuffWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "BuffStruct.h"

void UBuffWidget::SetUp(FBuffStruct& buff)
{
	Image->SetBrushFromTexture(buff.icon);
	Text->SetText(FText::AsNumber(buff.amount));
}