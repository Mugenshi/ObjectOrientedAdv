// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCPP.generated.h"

// Delegate for when start based on integers are changed.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FIntStatUpdated,
											   int32, OldValue,
											   int32, NewValue,
											   int32, MaxValue);

// Delegate for when the player dies.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerDied);

// Delegate for when stats based on floats are changed.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFloatStatUpdated,
											   float, OldValue,
											   float, NewValue,
											   float, MaxValue);

// Different actions involving the key wallet.
UENUM(BlueprintType)
enum class EPlayerKeyAction: uint8
{
	AddKey UMETA(Tooltip = "Attempt to add a key to the player's key wallet."),
	RemoveKey UMETA(Tooltip = "Attempt to remove a key from the player's key wallet."),
	TestKey UMETA(Tooltip = "Check if the player has a specific key.")

};

// Delegate for when actions occur with the player's keys.
// KeyString is the key involved in the action.
// KeyAction shows what was attempted.
// IsSuccess shows if the attempted action happend, or didn't.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FKeyWalletAction,
											   FString, KeyString,
											   EPlayerKeyAction, KeyAction,
											   bool, IsSuccess);

UCLASS()
class OBJECTORIENTEDADV_API APlayerCPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCPP();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region Keys

	// Add a key to the wallet if it isn't already in there.
	// If it is already in there, dont do anything.
	UFUNCTION(BlueprintCallable, Category="Player|KeyWallet")
	void AddKey(FString KeyToAdd);

	// Remove a key (do we even need to do that in our game?)
	// If the key isn't in the wallet, we do nothing.
	UFUNCTION(BlueprintCallable, Category="Player|KeyWallet")
	void RemoveKey(FString KeyToRemove);

	// Does the player have a given key?
	// Returns true if they do, and false if they dont.
	UFUNCTION(BlueprintPure, Category="Player|KeyWallet")
	bool IsPlayerCarryingKey(FString DesiredKey);

	// Triggered when something happens with the player's key wallet.
	UPROPERTY(BlueprintAssignable, Category = "Player|KeyWallet")
	FKeyWalletAction OnKeyWalletAction;

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
	TObjectPtr<class UUserWidget> ActiveWidget;

	// Player Keys
	TArray<FString> KeyWallet;

};
