// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultLayout.h"
#include "Components/TextBlock.h"

FText UDefaultLayout::GetMoneyText()
{
    PlayerCharacter = Cast<APlayerCPP>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    return FText::FromString(FString::FromInt(PlayerCharacter->GetMoney()));
}
