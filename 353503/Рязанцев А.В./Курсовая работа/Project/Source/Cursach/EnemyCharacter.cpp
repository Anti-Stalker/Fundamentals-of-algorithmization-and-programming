// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{	

}

void AEnemyCharacter::SetLevelMatrix(FString Currlevelname)
{
	if (!Currlevelname.IsEmpty()) {

		if (Currlevelname == "FirstLevel") {
			CurrLevelMap.setWidth(20);
			CurrLevelMap.setHieght(10);
			CurrLevelMap.generateEmptyMap();
			CurrLevelMap.setWallsFirst();

		}
		else if (Currlevelname == "SecondLevel") {
			CurrLevelMap.setWidth(13);
			CurrLevelMap.setHieght(10);
			CurrLevelMap.generateEmptyMap();
			CurrLevelMap.setWallsSecond();
		}
	}
}

void AEnemyCharacter::ConvertPlayerLocation(FVector WorldLoc)
{
	XPlayerPos = (static_cast<int>(WorldLoc.X) / 64);
	YPlayerPos = (static_cast<int>(WorldLoc.Y) / 64);
}
void AEnemyCharacter::ConvertEnemyLocation(FVector WorldLoc)
{
	XPos = (static_cast<int>(WorldLoc.X) / 64);
	YPos = (static_cast<int>(WorldLoc.Y) / 64);

	setWorldPos();
}

void AEnemyCharacter::setWorldPos() {
	EnemyPos.X = XPos * 64;
	EnemyPos.Y = YPos * 64;
	EnemyPos.Z = 50;
}

FVector AEnemyCharacter::MovePosUp()
{
	if (CurrLevelMap.Map[XPos][YPos - 1].IsPassable) {
		YPos--;
		setWorldPos();

		return EnemyPos;
	}

	return EnemyPos;
}

FVector AEnemyCharacter::MovePosDown()
{
	if (CurrLevelMap.Map[XPos][YPos + 1].IsPassable) {
		YPos++;
		setWorldPos();

		return EnemyPos;
	}

	return EnemyPos;
}

FVector AEnemyCharacter::MovePosRight()
{
	if (CurrLevelMap.Map[XPos + 1][YPos].IsPassable) {
		XPos++;
		setWorldPos();

		return EnemyPos;
	}

	return EnemyPos;
}

FVector AEnemyCharacter::MovePosLeft()
{
	if (CurrLevelMap.Map[XPos - 1][YPos].IsPassable) {
		XPos--;
		setWorldPos();

		return EnemyPos;
	}

	return EnemyPos;
}

void AEnemyCharacter::Action()
{
	int DistX = abs(XPlayerPos - XPos);
	int DistY = abs(YPlayerPos - YPos);

	if (DistX + DistY > 1) {
		ToMove();
	}
	else {
		ToAtack();
	}
}


void AEnemyCharacter::Move()
{
	EDirToMove Direction;
	
	bOnTheViewLine = true;
	for (int i = std::min(XPlayerPos, XPos); i < std::max(XPlayerPos, XPos); ++i) {
		if (!CurrLevelMap.Map[i][YPos].IsPassable) {
			bOnTheViewLine = false;
			break;
		}
	}	
	for (int i = std::min(YPlayerPos, YPos); i < std::max(YPlayerPos, YPos); ++i) {
		if (!CurrLevelMap.Map[XPos][i].IsPassable) {
			bOnTheViewLine = false;
			break;
		}
	}	

	if (bOnTheViewLine) {
		LastPos.X = XPlayerPos;
		LastPos.Y = YPlayerPos;		
	}
	
	if (YPos == LastPos.Y) {
		if (XPos < LastPos.X) {
			Direction = EDirToMove::Right;
		}
		else {
			Direction = EDirToMove::Left;
		}
	}
	else
	{
		if (YPos < LastPos.Y) {
			Direction = EDirToMove::Down;
		}
		else {
			Direction = EDirToMove::Up;
		}
	}


	MoveCall(Direction);
}

void AEnemyCharacter::RotateToAtack()
{
	if (XPlayerPos - XPos == 1) {
		this->SetActorRotation(FRotator(0, 0, 0), ETeleportType::ResetPhysics);
	}
	else if (XPlayerPos - XPos == -1) {
		this->SetActorRotation(FRotator(0, 180, 0), ETeleportType::ResetPhysics);
	}
	else if (YPlayerPos - YPos == 1) {
		this->SetActorRotation(FRotator(0, 90, 0), ETeleportType::ResetPhysics);
	}
	else if (YPlayerPos - YPos == -1) {
		this->SetActorRotation(FRotator(0, 270, 0), ETeleportType::ResetPhysics);
	}
}

void AEnemyCharacter::MoveCall(EDirToMove Direction)
{
	FRotator CurrRotation = this->GetActorRotation();

	switch (Direction)
	{
	case Up:
		this->SetActorRotation(FRotator(0, 270, 0), ETeleportType::ResetPhysics);
		MovePosUp();
		break;
	case Down:
		this->SetActorRotation(FRotator(0, 90, 0), ETeleportType::ResetPhysics);
		MovePosDown();
		break;
	case Left:
		this->SetActorRotation(FRotator(0, 180, 0), ETeleportType::ResetPhysics);
		MovePosLeft();
		break;
	case Right:
		this->SetActorRotation(FRotator(0, 0, 0), ETeleportType::ResetPhysics);
		MovePosRight();
		break;
	default:
		break;
	}
}

