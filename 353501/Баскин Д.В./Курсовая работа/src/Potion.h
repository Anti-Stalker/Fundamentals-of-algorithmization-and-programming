#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Potion.generated.h"

class UBuff;

UCLASS()
class COURSEWORK_API UPotion : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	FString name;
	UPROPERTY(EditAnywhere)
	UTexture2D* icon;
	UPROPERTY(EditAnywhere)
	UBuff* buff;
	UPROPERTY(EditAnywhere)
	FString description;
};
