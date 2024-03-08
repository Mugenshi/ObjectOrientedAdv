// Fill out your copyright notice in the Description page of Project Settings.


#include "IHNPC.h"

AIHNPC::AIHNPC() 
{
    PrimaryActorTick.bCanEverTick = true;
    name = "IHNPC npc";
    last_name = "npcing";
    hobbie = "AIDS";
}

FString AIHNPC::get_hobbie() 
{
    return hobbie;
}