// Fill out your copyright notice in the Description page of Project Settings.


#include "Blocking_Object.h"

ABlocking_Object::ABlocking_Object()
{
 	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));

	//Attach it to Root component. It will allow to work with group of tile as one instance
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void ABlocking_Object::ToDestroy(AMainCharacter* MainCharacter)
{
    if (MainCharacter)
    {    
		Destroy();
    }
}

void ABlocking_Object::BeginPlay()
{
	Super::BeginPlay();
	
}


