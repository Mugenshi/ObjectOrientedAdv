// Fill out your copyright notice in the Description page of Project Settings.


#include "ATMWidget.h"
#include "Components/TextBlock.h"

FText UATMWidget::GetMoneyText()
{
    ATM = Cast<AATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AATM::StaticClass()));
    return FText::FromString(FString::FromInt(ATM->GetMoneyATM()));
}

