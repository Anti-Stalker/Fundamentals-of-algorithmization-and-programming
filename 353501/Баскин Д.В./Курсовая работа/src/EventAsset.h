#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EventOption.h"
#include "EventAsset.generated.h"

UCLASS()
class COURSEWORK_API UEventAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	UTexture2D* image;
	UPROPERTY(EditAnywhere)
	FString text;
	UPROPERTY(EditAnywhere)
	TArray<UEventOption*> options;
};
