// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Gameframework/Actor.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "testDeer.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API AtestDeer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AtestDeer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Deer")
	void DecideNextAction(bool SkipDelay);

	UFUNCTION(BlueprintCallable, Category = "Deer")
	void RandomRoam();

};
