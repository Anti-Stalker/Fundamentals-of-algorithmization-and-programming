// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CURSACH_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetIsKey(bool IsKey);
	UFUNCTION(BlueprintCallable)
	bool GetIsKey();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsAtacking = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsWeapon = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsKey = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsRedVase = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsGreenVase = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsBlueVase = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsWhiteVase = false;
};
