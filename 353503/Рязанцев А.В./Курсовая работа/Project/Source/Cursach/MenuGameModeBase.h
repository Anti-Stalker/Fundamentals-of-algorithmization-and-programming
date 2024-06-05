// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BasicGameMode.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CURSACH_API AMenuGameModeBase : public ABasicGameMode
{
	GENERATED_BODY()
	
public:
	AMenuGameModeBase();

	void BeginPlay();
};
