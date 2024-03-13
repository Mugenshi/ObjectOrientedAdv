// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ObjectOrientedAdv/animals/Animals.h"
#include "Gameframework/Actor.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Wolf.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API AWolf : public ACharacter, public IAnimals
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	FString Say;

	UPROPERTY(EditAnywhere)
	FString Type;

public:
	 
	AWolf();

protected:
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

	 
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void DecideNextAction_Implementation(bool SkipDelay) override;

	void RandomRoam_Implementation() override;

	FString GetName_Implementation() override;

	FString GetType_Implementation() override;

	FString GetSay_Implementation() override;

};
