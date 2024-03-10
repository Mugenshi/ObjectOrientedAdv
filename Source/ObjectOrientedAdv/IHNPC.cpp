// Fill out your copyright notice in the Description page of Project Settings.


#include "IHNPC.h"

AIHNPC::AIHNPC() 
{
    PrimaryActorTick.bCanEverTick = true;
    name = "IHNPC npc";
    hobbie = "npcing";
    med_con = "AIDS";
}

FString AIHNPC::get_med_con() 
{
    return med_con;
}