// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPPController.h"
#include "PlayerCPP.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ObjectOrientedAdv/player/userinterface/PlayerCPPHUD.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void APlayerCPPController::OnPossess(APawn* aPawn)
{
    //call the parent method
    Super::OnPossess(aPawn);

    //store a reference to the Player's HUD.
    PlayerHUD = Cast<APlayerCPPHUD>(GetHUD());
    checkf(PlayerHUD, TEXT("Unable to get reference to the HUD."));

    //store a reference to the Player's Pawn.
    PlayerCharacter = Cast<APlayerCPP>(aPawn);
    checkf(PlayerCharacter,
        TEXT("APlayerCPPController derived classes should only possess APlayerCPP derived pawns."));

    //get a rederence to the EnhancedInputComponent.
    EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    checkf(EnhancedInputComponent,
        TEXT("Unable to get referenct to the EnhancedInpuComponent."));

    //get the local player subsystem
    //just a local variable, we don't need to refer to it again after this.
    UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
             ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    checkf(InputSubsystem,
        TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem."));

    checkf(InputMappingContext, TEXT("InputMappingContent was not specified."));
    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(InputMappingContext, 0);

    //bind the input actions.

    if (ActionMove) EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleMove);

    if (ActionLook) EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleLook);

    if (ActionJump) EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleJump);

    if (ActionInteract) EnhancedInputComponent->BindAction(ActionInteract, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleInteract);

    // if (ActionCycleUIMode) EnhancedInputComponent->BindAction(ActionCycleUIMode, ETriggerEvent::Triggered, this, &APlayerCPPController::HandleCycleUIMode);
}

void APlayerCPPController::OnUnPossess()
{
    // unbind things
    EnhancedInputComponent->ClearActionBindings();

    //call the parent method, in case it needs to do anything.
    Super::OnUnPossess();
}

void APlayerCPPController::HandleMove(const FInputActionValue& InputActionValue)
{

    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

    //add movement to player's Pawn.
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

    AddYawInput(LookAxisVector.X);
    AddPitchInput(LookAxisVector.Y);
}

void APlayerCPPController::HandleJump()
{
    //call the Jump method on the Player's Pawn.
    if (PlayerCharacter)
    {
        PlayerCharacter->UnCrouch();
        PlayerCharacter->Jump();
        UE_LOG(LogTemp, Warning, TEXT("Jumping"));
    }
}

void APlayerCPPController::HandleInteract()
{
    //call the Interact method on the Player's Pawn.
    if (PlayerCharacter)
    {
        FString isATM = PlayerCharacter->Interact();
        if (isATM == "true")
        {
            PlayerHUD->CycleToNextViewMode(1);
            bShowMouseCursor = true;
            UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(this, PlayerHUD->GetCurrentWidget(), EMouseLockMode::DoNotLock);
        }
        else if (isATM == "note")
        {
            PlayerHUD->CycleToNextViewMode(2);
            bShowMouseCursor = true;
            UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(this, PlayerHUD->GetCurrentWidget(), EMouseLockMode::DoNotLock);
        }
    }
}

// void APlayerCPPController::HandleCycleUIMode()
// {
//     if (PlayerHUD)
//     {
//         PlayerHUD->CycleToNextViewMode();
//     }
// }
