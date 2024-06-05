// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "MapTemplate.h"
#include "Level_1.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(BlueprintType)
class CURSACH_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//return true if alive, false if died
	UFUNCTION(BlueprintCallable)
	bool Atack(float BaseDamage, ABaseCharacter* Target);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	float HitPoints = 100;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual bool Converter(int value);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsMoving;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
