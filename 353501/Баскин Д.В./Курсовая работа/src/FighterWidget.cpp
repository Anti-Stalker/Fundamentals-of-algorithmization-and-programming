#include "FighterWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "EnemyAction.h"
#include "BuffWidget.h"
#include "Components/Button.h"
#include "Animation/WidgetAnimation.h"

void UFighterWidget::NativeConstruct()
{
	Button->OnClicked.AddDynamic(this, &UFighterWidget::OnClicked);
}

void UFighterWidget::SetFighter(UTexture2D* image)
{
	FighterVisuals->SetBrushFromTexture(image);
}

void UFighterWidget::SetBlock(int block)
{
	BlockText->SetText(FText::AsNumber(block));
}

void UFighterWidget::SetHealth(int health, int maxHealth)
{
	HealthText->SetText(FText::Format(FText::FromString(TEXT("{0}/{1} HP")), FText::AsNumber(health), FText::AsNumber(maxHealth)));
	HealthBar->SetPercent(health / (float)maxHealth);
}

void UFighterWidget::PlayAttackAnimation()
{
	PlayAnimation(AttackAnimation);
}

void UFighterWidget::PlayBlockAnimation()
{
	PlayAnimation(BlockAnimation);
}

void UFighterWidget::PlayDamageReceiveAnimation()
{
	PlayAnimation(DamageReceiveAnimation);
}

void UFighterWidget::PlayAttackIndicator()
{
	PlayAnimation(AttackTarget);
}

void UFighterWidget::PlaySelfIndicator()
{
	PlayAnimation(SelfTarget);
}

void UFighterWidget::OnClicked()
{
	OnFighterClickedEvent.Broadcast(this);
}

void UFighterWidget::SetIntention(UTexture2D* image, int amount)
{
	if (image == nullptr)
	{
		IntentionImage->SetOpacity(0);
	}
	IntentionImage->SetBrushFromTexture(image);
	IntentionText->SetText((amount ? FText::AsNumber(amount) : FText::FromString("")));
}

void UFighterWidget::AddBuffs(TArray<FBuffStruct> buffs)
{
	BuffsBox->ClearChildren();
	for (auto& buff : buffs)
	{
		UBuffWidget* Buff = Cast<UBuffWidget>(CreateWidget(GetWorld(), buffWidget));
		buff.widget = Buff;
		Buff->SetUp(buff);
		BuffsBox->AddChildToHorizontalBox(Buff);
	}
}
