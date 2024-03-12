// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Components/Widget.h"
#include "PlayerCPPHUD.generated.h"


// Forward Declaration
class APlayerCPP;
class UDefaultLayout;
class UATMWidget;
class UCreditCardNote;

UENUM(BlueprintType)
enum class EHudViewMode: uint8
{
	DefaultLayout UMETA(Tooltip="Default Widget"),
	ATMWidget UMETA(Tooltip="ATM Widget"),
	CreditCardNote UMETA(Tooltip="Credit Card Note")
};

inline EHudViewMode& operator++(EHudViewMode& ViewMode)
{	
	if (ViewMode == EHudViewMode::ATMWidget)
		ViewMode = EHudViewMode::DefaultLayout;
	else
		ViewMode = static_cast<EHudViewMode>(static_cast<int>(ViewMode) + 1);

	return ViewMode;
}

inline EHudViewMode& operator--(EHudViewMode& ViewMode)
{
	if (ViewMode == EHudViewMode::DefaultLayout)
		ViewMode = EHudViewMode::ATMWidget;
	else
		ViewMode = static_cast<EHudViewMode>(static_cast<int>(ViewMode) - 1);
	return ViewMode;
}

UCLASS(Abstract)
class OBJECTORIENTEDADV_API APlayerCPPHUD : public AHUD
{
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDefaultLayout> DefaultLayoutClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UATMWidget> ATMWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCreditCardNote> CreditCardNoteClass;

	UFUNCTION(BlueprintCallable)
	void SetViewMode(EHudViewMode NewViewMode);

	// Change to the next viewmode 
	UFUNCTION(BlueprintCallable) 
	void CycleToNextViewMode(int choice);

	UWidget* GetCurrentWidget();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	// Determines what UI elements should be displayed.
	UPROPERTY(EditAnywhere)
	EHudViewMode CurrentViewMode = EHudViewMode::DefaultLayout;

	void UpdateWidget();

	void ClearAllHandlers();

	UPROPERTY()
	TObjectPtr<UDefaultLayout> DefaultLayout = nullptr;

	UPROPERTY()
	TObjectPtr<UATMWidget> ATMWidget = nullptr;

	UPROPERTY()
	TObjectPtr<UCreditCardNote> CreditCardNote = nullptr;

	UPROPERTY()
	TObjectPtr<UWorld> World = nullptr;

	UPROPERTY()
	TObjectPtr<APlayerCPP> PlayerCharacter = nullptr;

	GENERATED_BODY()
};
