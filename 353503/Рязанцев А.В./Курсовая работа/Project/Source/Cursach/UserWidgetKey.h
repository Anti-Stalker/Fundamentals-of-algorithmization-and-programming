// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetKey.generated.h"

class AMainCharacter;

UCLASS()
class CURSACH_API UUserWidgetKey : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ESlateVisibility CharacterHasKey();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ESlateVisibility CharacterRedVase();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ESlateVisibility CharacterGreenVase();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ESlateVisibility CharacterBlueVase();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ESlateVisibility CharacterWhiteVase();

};
