#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Buff.generated.h"

UCLASS()
class COURSEWORK_API UBuff : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString name;

	UPROPERTY(EditAnywhere)
	bool applyToSelf;

	UPROPERTY(EditAnywhere)
	int amount;

	UPROPERTY(EditAnywhere)
	UTexture2D* icon;
};
