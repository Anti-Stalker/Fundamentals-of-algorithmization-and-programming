#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuffStruct.h"
#include "EnemyAction.generated.h"

UENUM()
enum class EActionType
{
	Attack,
	Block,
	Strategic
};

UCLASS()
class COURSEWORK_API UEnemyAction : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	int chance;

	UPROPERTY(EditAnywhere)
	int amount;

	UPROPERTY(EditAnywhere)
	UBuff* buff;

	UPROPERTY(EditAnywhere)
	EActionType actionType;

	UPROPERTY(EditAnywhere)
	UTexture2D* actionIcon;
};
