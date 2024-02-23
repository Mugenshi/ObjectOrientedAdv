// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ObjectOrientedAdv/animals/Animals.h"
#include "Gameframework/Actor.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Pig.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API APig : public ACharacter, public IAnimals
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Name;

public:
	// Sets default values for this character's properties
	APig();

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
