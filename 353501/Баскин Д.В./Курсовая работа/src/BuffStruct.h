#pragma once

#include "CoreMinimal.h"
#include "BuffStruct.generated.h"

class UBuff;
class UBuffWidget;

USTRUCT()
struct COURSEWORK_API FBuffStruct
{
	GENERATED_BODY()

	FBuffStruct() = default;

	FBuffStruct(UBuff* buff);

	bool operator==(const FBuffStruct& other) const;
	
	UPROPERTY()
	FString name;

	UPROPERTY()
	int amount;

	UPROPERTY()
	bool applyToSelf;

	UPROPERTY()
	UTexture2D* icon;

	UPROPERTY()
	UBuffWidget* widget;
};
