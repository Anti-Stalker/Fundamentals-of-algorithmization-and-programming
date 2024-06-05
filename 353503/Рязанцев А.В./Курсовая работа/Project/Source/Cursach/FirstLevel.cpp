// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstLevel.h"

LevelMatrix::LevelMatrix()
{
}

void LevelMatrix::setWallsSecond()
{
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < hiegth; ++j) {
			Map[i][j].IsPassable = false;
		}
	}

	for (int i = 5; i < 8; ++i)
	{
		Map[i][0].IsPassable = true;
	}
	Map[6][1].IsPassable = true;

	for (int i = 2; i < 11; ++i)
	{
		Map[i][2].IsPassable = true;
		Map[i][8].IsPassable = true;
	}
	for (int i = 2; i < 11; ++i)
	{
		Map[i][2].IsPassable = true;
	}

	for (int i = 2; i < 9; ++i)
	{
		Map[3][i].IsPassable = true;
		Map[9][i].IsPassable = true;
	}
	for (int i = 10; i < 13; ++i)
	{
		Map[i][5].IsPassable = true;
	}
}

void LevelMatrix::setWallsFirst()
{
	// ===========================

	for (int i = 0; i < 9; ++i) {
		Map[0][i].IsPassable = false;
	}
	for (int i = 0; i < 20; ++i) {
		Map[i][9].IsPassable = false;
	}
	for (int i = 0; i < 20; ++i) {
		Map[i][0].IsPassable = false;
	}
	for (int i = 0; i < 10; ++i) {
		Map[19][i].IsPassable = false;
	}

	for (int i = 4; i < 19; ++i) {
		if (i == 13) {
			continue;
		}
		Map[i][3].IsPassable = false;
	}
	for (int i = 4; i < 19; ++i) {
		if (i == 13) {
			continue;
		}
		Map[i][4].IsPassable = false;
	}
	for (int i = 4; i < 19; ++i) {
		if (i == 13) {
			continue;
		}
		Map[i][5].IsPassable = false;
	}
	for (int i = 4; i < 19; ++i) {
		if (i == 12 || i == 13 || i == 14) {
			continue;
		}
		Map[i][6].IsPassable = false;
	}

	Map[4][1].IsPassable = false;
	Map[4][2].IsPassable = false;
}

void LevelMatrix::generateEmptyMap()
{
	FTile ex = FTile();
	TArray<FTile> Row;

	for (int Index = 0; Index < hiegth; ++Index) {
		Row.Add(ex);
	}

	for (int Index = 0; Index < width; ++Index) {
		Map.Add(Row);
	}

}

LevelMatrix::~LevelMatrix()
{
}
