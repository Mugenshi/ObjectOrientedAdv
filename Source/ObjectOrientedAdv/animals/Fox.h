// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ObjectOrientedAdv/animals/Animals.h"
#include "GameFramework/Actor.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Fox.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API AFox : public ACharacter, public IAnimals
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;

public:
	// Sets default values for this character's properties
	AFox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void DecideNextAction_Implementation(bool SkipDelay) override;

	void RandomRoam_Implementation() override;

	FString GetName_Implementation() override;

};
