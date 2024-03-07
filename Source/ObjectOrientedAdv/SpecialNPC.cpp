// SpecialNPC.cpp

#include "SpecialNPC.h"

ASpecialNPC::ASpecialNPC()
{
    PrimaryActorTick.bCanEverTick = true;
    name = "Special npc";
    hobbie = "npcing";
}

FString ASpecialNPC::get_hobbie()
{
    return hobbie;
}
