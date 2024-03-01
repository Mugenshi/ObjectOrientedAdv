// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPPController.h"
#include "PlayerCPP.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerCPPHUD.h"

void APlayerCPPController::OnPossess(APawn* aPawn)
{
    // Call the parent method, to let it do anything it needs to.
    Super::OnPossess(aPawn);

    // Store a reference to the Player's HUD.
    PlayerHUD = Cast<APlayerCPPHUD>(GetHUD());
    checkf(PlayerHUD, TEXT("Unable to get reference to the HUD."));

    // Store a reference to the Player's Pawn.
    PlayerCharacter = Cast<APlayerCPP>(aPawn);
    checkf(PlayerCharacter,
        TEXT("APlayerCPPController derived classes should only possess APlayerCPP derived pawns."));

    // Get a rederence to the EnhancedInputComponent.
    EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    checkf(EnhancedInputComponent,
        TEXT("Unable to get referenct to the EnhancedInpuComponent."));

    // Get the local player subsystem
    // Just a local variable, we don't need to refer to it again after this.
    UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
             ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    checkf(InputSubsystem,
        TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem."));

    // Wipe existing mappings, and add our mapping.
    checkf(InputMappingContext, TEXT("InputMappingContent was not specified."));
    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(InputMappingContext, 0);

    // Bind the input actions.
    // Only attempt to bind if valid values were provided.
    if (ActionMove) EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleMove);

    if (ActionLook) EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleLook);

    if (ActionJump) EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleJump);

    if (ActionInteract) EnhancedInputComponent->BindAction(ActionInteract, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleInteract);

    // if (ActionCycleUIMode) EnhancedInputComponent->BindAction(ActionCycleUIMode, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleCycleUIMode);
}

void APlayerCPPController::OnUnPossess()
{
    // Unbind things here.
    EnhancedInputComponent->ClearActionBindings();

    // Call the parent method, in case it needs to do anything.
    Super::OnUnPossess();
}

void APlayerCPPController::HandleMove(const FInputActionValue& InputActionValue)
{
    // Value is a Vector2D
    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

    // Add movement to the Player's Pawn.
    if (PlayerCharacter)
    {
        PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), MovementVector.Y);
        PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
    }
}

void APlayerCPPController::HandleLook(const FInputActionValue& InputActionValue)
{
    // Value is a Vector2D
    const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

    // Add yaw and pitch to the Player's Pawn.
    AddYawInput(LookAxisVector.X);
    AddPitchInput(LookAxisVector.Y);
}

void APlayerCPPController::HandleJump()
{
    // Call the Jump method on the Player's Pawn.
    if (PlayerCharacter)
    {
        PlayerCharacter->UnCrouch();
        PlayerCharacter->Jump();
        UE_LOG(LogTemp, Warning, TEXT("Jumping"));
    }
}

void APlayerCPPController::HandleInteract()
{
    // Call the Interact method on the Player's Pawn.
    if (PlayerCharacter)
    {
        PlayerCharacter->Interact();
    }
}

// void APlayerCPPController::HandleCycleUIMode()
// {
//     if (PlayerHUD)
//     {
//         PlayerHUD->CycleToNextViewMode();
//     }
// }
