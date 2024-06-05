// Fill out Xour copXright notice in the Description page of Project Settings.


#include "PathFinder.h"

PathFinder::PathFinder()
{
}

PathFinder::~PathFinder()
{
}

void PathFinder::SetTileInfo(FTile &Tile, int X, int Y, 
										  int EndX, int EndY, 
										  int PtX, int PtY, 
										  int Cost)
{
	if (Tile.IsPassable && !Tile.bIsSet)
	{
		FVector2D Temp = FVector2D(X, Y);

		Tile.EuristicValue = abs(EndX - X) + abs(EndY - Y) * 10;
		Tile.PathValue = 10 + Cost;

		Tile.TotalValue = Tile.EuristicValue + Tile.PathValue;

		Tile.PointsTo.X = PtX;
		Tile.PointsTo.Y = PtY;

		Tile.bIsSet = true;

		CheckedTiles.Add(Temp); // here m
	}
	else
	{
		return;
	}
}

void PathFinder::SetInfo(TArray<TArray<FTile>>& Level, const int X, const int Y, const int EndX, const int EndY, int Cost)
{		
	SetTileInfo(Level[X - 1][Y], X - 1, Y, EndX, EndY, X, Y, Level[X][Y].PathValue);
	SetTileInfo(Level[X + 1][Y], X + 1, Y, EndX, EndY, X, Y, Level[X][Y].PathValue);
	SetTileInfo(Level[X][Y - 1], X, Y - 1, EndX, EndY, X, Y, Level[X][Y].PathValue);
	SetTileInfo(Level[X][Y + 1], X, Y + 1, EndX, EndY, X, Y, Level[X][Y].PathValue);

	if (abs(EndX - X) + abs(EndY - Y) <= 1) {
		return;
	}

	for (const auto &Index : CheckedTiles) {
		if (Level[Index.X][Index.Y].TotalValue < CurrMinValue) {
			CurrMinValue = Level[Index.X][Index.Y].TotalValue;
			MinIndex = Index;
		}	
	}
		
	return SetInfo(Level, MinIndex.X, MinIndex.Y, EndX, EndY, Level[MinIndex.X][MinIndex.Y].PathValue);
}

EDirToMove PathFinder::Direction(LevelMatrix Level, const int StartX, const int StartY, const int EndX, const int EndY)
{
	SetInfo(Level.Map, StartX, StartY, EndX, EndY, 0);
	
	TArray<FVector2D> Path;
	FVector2D CurrPtr = Level.Map[EndX][EndY].PointsTo;
	int counter = 0;

	while (CurrPtr != FVector2D(StartX, StartY)) {
		Path.Add(CurrPtr);
		counter++;
		CurrPtr = Level.Map[CurrPtr.X][CurrPtr.Y].PointsTo;
	}
	
	FVector2D NextTile = Path[counter];

	if (NextTile.X == StartX + 1) {
		return EDirToMove::Right;
	}
	if (NextTile.X == StartX - 1) {
		return EDirToMove::Left;
	}
	if (NextTile.Y == StartY - 1) {
		return EDirToMove::Up;
	}
	if (NextTile.Y == StartY + 1) {
		return EDirToMove::Down;
	}
	
	return EDirToMove::Stay;
}
