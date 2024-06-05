// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ABaseCharacter::Atack(float BaseDamage, ABaseCharacter* Target)
{
	if (Target->HitPoints <= 0) { return false; }
	
	float TotalDamage = BaseDamage;

	float RandNum = rand() % 20;
	int HitPart = rand() % 4;
	if (HitPart == 0) {
		TotalDamage += RandNum * 2;
	}
	if (HitPart == 1) {
		TotalDamage += RandNum * 1.5;
	}
	if (HitPart == 2) {
		TotalDamage += RandNum * 1.3;
	}
	if (HitPart == 3) {
		TotalDamage += RandNum;
	}

	float changed_health = Target->HitPoints - BaseDamage + TotalDamage / 10;
	
	if (changed_health <= 0) 
	{
		return false;
	}

	Target->HitPoints = changed_health;

	return true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



bool ABaseCharacter::Converter(int value)
{
	if (value != 0) {
		return true;
	}

	return false;
}