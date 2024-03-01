// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCPPController.generated.h"


// Forward declarations
class UEnhancedInputComponent;
class APlayerCPP;
class UInputMappingContext;
class APlayerCPPHUD;


UCLASS(Abstract)
class OBJECTORIENTEDADV_API APlayerCPPController : public APlayerController
{
public:
	// The Input Action to map movement.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionMove = nullptr;

	// The Input Action to map to looking around.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionLook = nullptr;

	// The Input Action to map to jumping.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionJump = nullptr;

	// The Input Action to cycle UI display mode.
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|UI")
	// TObjectPtr<UInputAction> ActionCycleUIMode = nullptr;

	// The Input Mapping Context to use.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

protected:
	// Action Handlers Functions
	void HandleMove(const FInputActionValue& InputActionValue);
	void HandleLook(const FInputActionValue& InputActionValue);
	void HandleJump();
	void HandleSprint();
	// void HandleCycleUIMode();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private:
	// Used to store a reference to the InputComponent cast to an EnhancedInputComponent.
	UPROPERTY()
	TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = nullptr;

	// Used to store a reference to the pawn we are controlling.
	UPROPERTY()
	TObjectPtr<APlayerCPP> PlayerCharacter = nullptr;

	// Used to store a reference to the pawn we are controlling.
	UPROPERTY()
	TObjectPtr<APlayerCPPHUD> PlayerHUD = nullptr;

	GENERATED_BODY()
	
};
