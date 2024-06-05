// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

void AMainCharacter::SetIsKey(bool IsKey)
{
    bIsKey = IsKey;
}

bool AMainCharacter::GetIsKey()
{
    return bIsKey;
}
