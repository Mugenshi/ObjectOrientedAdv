// SpecialNPC.cpp

#include "SpecialNPC.h"

ASpecialNPC::ASpecialNPC()
{
    PrimaryActorTick.bCanEverTick = true;
    name = "Special npc";
    last_name = "npcing";
}

FString ASpecialNPC::get_last_name()
{
    return last_name;
}
