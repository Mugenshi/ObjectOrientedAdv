// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerCPPHUD.generated.h"


// Forward Declaration
class APlayerCPP;
class UDefaultLayout;

// UENUM(BlueprintType)
// enum class EHudViewMode: uint8
// {
// 	CleanAndPristine UMETA(Tooltip="Get that mess outta my face!"),
// 	Minimal UMETA(Tooltip="Just the facts, ma'am"),
// 	Moderate UMETA(Tooltip="I like a little clutter"),
// 	SensoryOverload UMETA(Tooltip="I want it all!")
// };

// inline EHudViewMode& operator++(EHudViewMode& ViewMode)
// {	
// 	if (ViewMode == EHudViewMode::SensoryOverload)
// 		ViewMode = EHudViewMode::CleanAndPristine;
// 	else
// 		ViewMode = static_cast<EHudViewMode>(static_cast<int>(ViewMode) + 1);

// 	return ViewMode;
// }

// inline EHudViewMode& operator--(EHudViewMode& ViewMode)
// {
// 	if (ViewMode == EHudViewMode::CleanAndPristine)
// 		ViewMode = EHudViewMode::SensoryOverload;
// 	else
// 		ViewMode = static_cast<EHudViewMode>(static_cast<int>(ViewMode) - 1);
// 	return ViewMode;
// }

UCLASS(Abstract)
class OBJECTORIENTEDADV_API APlayerCPPHUD : public AHUD
{
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDefaultLayout> DefaultLayoutClass;

	// Change to the next viewmode 
	// UFUNCTION(BlueprintCallable) 
	// void CycleToNextViewMode();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	// Determines what UI elements should be displayed.
	// UPROPERTY(EditAnywhere)
	// EHudViewMode CurrentViewMode = EHudViewMode::Minimal;

	UPROPERTY()
	TObjectPtr<UDefaultLayout> DefaultLayout = nullptr;

	UPROPERTY()
	TObjectPtr<UWorld> World = nullptr;

	UPROPERTY()
	TObjectPtr<APlayerCPP> PlayerCharacter = nullptr;

	GENERATED_BODY()
};
