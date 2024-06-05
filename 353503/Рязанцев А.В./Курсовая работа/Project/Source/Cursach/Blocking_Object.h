// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MainCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blocking_Object.generated.h"

UCLASS(BlueprintType)
class CURSACH_API ABlocking_Object : public AActor
{
	GENERATED_BODY()
	
public:	

	ABlocking_Object();

	UFUNCTION(BlueprintCallable)
	void ToDestroy(AMainCharacter* MainCharacter);

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

};
