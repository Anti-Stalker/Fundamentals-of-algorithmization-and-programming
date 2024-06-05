#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Relic.generated.h"

class UBuff;

UCLASS()
class COURSEWORK_API URelic : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FString relicName;

	UPROPERTY(EditAnywhere)
	UBuff* relicBuff;

	UPROPERTY(EditAnywhere)
	FString relicDescription;

	UPROPERTY(EditAnywhere)
	UTexture2D* relicIcon;
};
