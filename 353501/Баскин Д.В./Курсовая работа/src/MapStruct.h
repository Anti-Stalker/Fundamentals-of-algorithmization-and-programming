#pragma once

#include "CoreMinimal.h"
#include "FloorStruct.h"
#include "MapStruct.generated.h"

USTRUCT()
struct COURSEWORK_API FMapStruct
{
	GENERATED_BODY()

public:
	FMapStruct();

	UPROPERTY()
	TArray<FFloorStruct> act;
	UPROPERTY()
	TArray<FNodeStruct> activeNodes;
};
