// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPPHUD.h"
#include "ObjectOrientedAdv/player/character/PlayerCPP.h"
#include "DefaultLayout.h"

void APlayerCPPHUD::BeginPlay()
{
    Super::BeginPlay();
    // Get a reference to the world.
    World = GetWorld();
    checkf(World, TEXT("Unable to get reference to the World."));

    // Ensure we have valid values for the 3 classes of widget used by the HUD.
    checkf(DefaultLayoutClass, TEXT("DefaultLayoutClass is not set."));

    // Create the default layout widget.
    DefaultLayout = CreateWidget<UDefaultLayout>(World, DefaultLayoutClass);
    DefaultLayout->AddToViewport();
}

void APlayerCPPHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    // Call the parent method, in case it needs to do anything.
    Super::EndPlay(EndPlayReason);
    // Clear the reference to the world.
    World = nullptr;
}
