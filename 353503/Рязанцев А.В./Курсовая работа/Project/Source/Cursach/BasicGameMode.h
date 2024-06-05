// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "MainCharacter.h"
#include "Level_1.h"
#include "EnemyCharacter.h"
#include "CharacterHUD.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BasicGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CURSACH_API ABasicGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABasicGameMode();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AMainCharacter* Character;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* Key;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEnemyCharacter* EnemyCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsComplited = false;

	void BeginPlay();
};
