// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPPHUD.h"
#include "ObjectOrientedAdv/player/character/PlayerCPP.h"
#include "DefaultLayout.h"
#include "ATMWidget.h"

void APlayerCPPHUD::BeginPlay()
{
    Super::BeginPlay();
    // Get a reference to the world.
    World = GetWorld();
    checkf(World, TEXT("Unable to get reference to the World."));

    // Ensure we have valid values for the 3 classes of widget used by the HUD.
    checkf(DefaultLayoutClass, TEXT("DefaultLayoutClass is not set."));
    checkf(ATMWidgetClass, TEXT("ATMWidgetClass is not set."));

    // Create the default layout widget.
    DefaultLayout = CreateWidget<UDefaultLayout>(World, DefaultLayoutClass);
    DefaultLayout->AddToViewport();
    DefaultLayout->SetVisibility(ESlateVisibility::Collapsed);

    ATMWidget = CreateWidget<UATMWidget>(World, ATMWidgetClass);
    ATMWidget->AddToViewport();
    ATMWidget->SetVisibility(ESlateVisibility::Collapsed);

    UpdateWidget();
}

void APlayerCPPHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    // Call the parent method, in case it needs to do anything.
    Super::EndPlay(EndPlayReason);
    // Clear the reference to the world.
    World = nullptr;
}

void APlayerCPPHUD::SetViewMode(EHudViewMode NewViewMode)
{
    // Set the view mode.
    CurrentViewMode = NewViewMode;
    // Update the widget.
    UpdateWidget();
}

void APlayerCPPHUD::CycleToNextViewMode()
{
    // Cycle to the next view mode.
    ++CurrentViewMode;
    
    GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
        FString::Printf(TEXT("CurrentViewMode: %d"), static_cast<int>(CurrentViewMode)));
    
    UpdateWidget();
    
}

void APlayerCPPHUD::UpdateWidget()
{
    // Show the widget for the current view mode.
    switch (CurrentViewMode)
    {
    case EHudViewMode::DefaultLayout:
        DefaultLayout->SetVisibility(ESlateVisibility::Visible);
        ATMWidget->SetVisibility(ESlateVisibility::Collapsed);
        break;
    case EHudViewMode::ATMWidget:
        DefaultLayout->SetVisibility(ESlateVisibility::Collapsed);
        ATMWidget->SetVisibility(ESlateVisibility::Visible);
        break;
    default:
        break;
    }
}

UWidget* APlayerCPPHUD::GetCurrentWidget()
{
    // Get the user widget.
    if (CurrentViewMode == EHudViewMode::DefaultLayout)
    {
        return DefaultLayout;
    }
    else
    {
        return ATMWidget;
    }
}