// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetCPPBase.h"

#if WITH_EDITOR
const FText UWidgetCPPBase::GetPaletteCategory()
{
    return NSLOCTEXT("UMG", "CustomPaletteCategory", "ObjectOrientedAdv");
}
#endif

