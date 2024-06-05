// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum EDirToMove {
	Up,
	Down,
	Left,
	Right,
	Stay
};

struct FTile
{
	FTile() = default;
	bool IsPassable = true;
	bool bIsSet = false;
	int PathValue = 0;
	int EuristicValue = 0;
	int TotalValue = 0;
	FVector2D PointsTo = {0, 0};
};
/**
 * 
 */
class CURSACH_API LevelMatrix
{
public:
	TArray<TArray<FTile>> Map;

	LevelMatrix();
	~LevelMatrix();
	
	int width = 0;
	int hiegth = 0;
	
	void setWidth(int w) { width = w; }
	void setHieght(int h) { hiegth = h; }
	void generateEmptyMap();
	void setWallsFirst();
	void setWallsSecond();
};
