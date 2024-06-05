#pragma once

#include "CoreMinimal.h"
#include <Kismet/KismetMathLibrary.h>
#include "NodeStruct.generated.h"

UENUM()
enum class ENodeType
{
	Empty,
	Mob,
	Elite,
	Event,
	Chest,
	Shop,
	Rest,
	Boss
};

USTRUCT()
struct COURSEWORK_API FNodeStruct
{
	GENERATED_BODY()

public:
	FNodeStruct();

	bool operator==(const FNodeStruct& other) const;

	UPROPERTY()
	ENodeType type;

	UPROPERTY()
	FRandomStream seed;
};
