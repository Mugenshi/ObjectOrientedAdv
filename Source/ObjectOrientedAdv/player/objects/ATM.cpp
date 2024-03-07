// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectOrientedAdv/player/objects/ATM.h"

// Sets default values
AATM::AATM()
{
    MoneyATM = 0;
}

void AATM::SetMoneyATM(int Money)
{
    MoneyATM += Money;

}

int AATM::GetMoneyATM()
{
    return MoneyATM;
}

