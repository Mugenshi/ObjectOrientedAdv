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
	
	APig();

protected:
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

	 
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void DecideNextAction_Implementation(bool SkipDelay) override;

	void RandomRoam_Implementation() override;

	FString GetName_Implementation() override;

};
