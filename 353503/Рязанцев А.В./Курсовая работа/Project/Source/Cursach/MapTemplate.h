// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTemplate.generated.h"


UCLASS()
class CURSACH_API AMapTemplate : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMapTemplate();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	bool bLevelComplited = false;
};
