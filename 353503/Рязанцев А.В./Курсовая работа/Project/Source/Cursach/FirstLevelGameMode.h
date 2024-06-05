// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicGameMode.h"
#include "FirstLevelGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CURSACH_API AFirstLevelGameMode : public ABasicGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* Door;

};
