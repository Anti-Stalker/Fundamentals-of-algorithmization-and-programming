// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FirstLevel.h"
#include "CoreMinimal.h"

struct UEPIDR {
	int X = 0;
	int Y = 0;
};

/**
 * 
 */
class CURSACH_API PathFinder
{
public:
	PathFinder();
	~PathFinder();

	TArray<FVector2D> CheckedTiles;
	int CurrMinValue;
	FVector2D MinIndex;

	void SetTileInfo(FTile& Tile, int X, int Y, int EndX, int EndY, int PtX, int PtY, int Cost);
	void SetInfo(TArray<TArray<FTile>>& Level, const int X, const int Y, const int EndX, const int EndY, int Cost);

	EDirToMove Direction(LevelMatrix Level, const int StartX, const int StartY, const int EndX, const int EndY);
};
