#pragma once

#include "CoreMinimal.h"
#include "NodeStruct.h"
#include "PathStruct.h"
#include "FloorStruct.generated.h"

USTRUCT()
struct COURSEWORK_API FFloorStruct
{
	GENERATED_BODY()

public:
	FFloorStruct();

	UPROPERTY()
	TArray<FNodeStruct> nodes;

	UPROPERTY()
	TArray<FPathStruct> paths;

};
