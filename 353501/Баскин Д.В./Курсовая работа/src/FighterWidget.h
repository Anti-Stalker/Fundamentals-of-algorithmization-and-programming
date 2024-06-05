#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuffStruct.h"
#include "FighterWidget.generated.h"

class UButton;
class UImage;
class UProgressBar;
class UTextBlock;
class UHorizontalBox;
class UEnemyAction;
class UBuffWidget;
class UWidgetAnimation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFighterClicked, UFighterWidget*, Fighter);

UCLASS()
class COURSEWORK_API UFighterWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> buffWidget;
	
	UPROPERTY(meta = (BindWidget))
	UImage* IntentionImage;
	UPROPERTY(meta = (BindWidget))
	UImage* FighterVisuals;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* BlockText;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HealthText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* IntentionText;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* BuffsBox;
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* AttackAnimation;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* BlockAnimation;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* DamageReceiveAnimation;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* SelfTarget;
	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* AttackTarget;

public:

	FOnFighterClicked OnFighterClickedEvent;

	UFUNCTION()
	void PlayAttackAnimation();
	UFUNCTION()
	void PlayBlockAnimation();
	UFUNCTION()
	void PlayDamageReceiveAnimation();
	UFUNCTION()
	void PlayAttackIndicator();
	UFUNCTION()
	void PlaySelfIndicator();
	UFUNCTION()
	void OnClicked();
	UFUNCTION()
	void SetIntention(UTexture2D* image = nullptr, int amount = 0);
	UFUNCTION()
	void SetFighter(UTexture2D* image);
	UFUNCTION()
	void SetBlock(int block);
	UFUNCTION()
	void SetHealth(int health, int maxHealth);

	UFUNCTION()
	void AddBuffs(TArray<FBuffStruct> buffs);
};
