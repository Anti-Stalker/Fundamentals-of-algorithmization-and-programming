#pragma once

#include "CoreMinimal.h"
#include "PathStruct.generated.h"

USTRUCT()
struct COURSEWORK_API FPathStruct
{
	GENERATED_BODY()
	
	FPathStruct();
	FPathStruct(int From, int To);

	bool operator==(const FPathStruct& other) const;

	UPROPERTY()
	int From;
	UPROPERTY()
	int To;
};
