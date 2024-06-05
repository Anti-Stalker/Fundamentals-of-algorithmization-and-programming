// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PathFinder.h"
#include "Engine/World.h"
#include "FirstLevel.h"
#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "EnemyCharacter.generated.h"


/**
 * 
 */
UCLASS()
class CURSACH_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	AEnemyCharacter();

	FVector2D LastPos = { 0,0 };
	bool bOnTheViewLine;

	UWorld* CurrWorld;
	LevelMatrix CurrLevelMap;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsKilled = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector EnemyPos;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int XPos = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int YPos = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int XPlayerPos = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int YPlayerPos = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AngreRadious = 5;

	
	UFUNCTION(BlueprintCallable)
	FVector MovePosUp();
	UFUNCTION(BlueprintCallable)
	FVector MovePosDown();
	UFUNCTION(BlueprintCallable)
	FVector MovePosLeft();
	UFUNCTION(BlueprintCallable)
	FVector MovePosRight();
	
	UFUNCTION(BlueprintCallable)
	void Action();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToAtack();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToMove();
	UFUNCTION(BlueprintCallable)
	void Move();
	UFUNCTION(BlueprintCallable)
	void RotateToAtack();

	UFUNCTION(BlueprintCallable)
	void SetLevelMatrix(FString Currlevelname);
	UFUNCTION(BlueprintCallable)
	void ConvertEnemyLocation(FVector WorldLoc);
	UFUNCTION(BlueprintCallable)
	void ConvertPlayerLocation(FVector WorldLoc);
	UFUNCTION(BlueprintCallable)
	void setWorldPos();
	
	void MoveCall(EDirToMove Direction);
};
