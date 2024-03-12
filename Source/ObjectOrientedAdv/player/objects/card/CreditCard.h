// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreditCard.generated.h"

UCLASS(Abstract)
class OBJECTORIENTEDADV_API ACreditCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreditCard();

	UFUNCTION()
	virtual FString GetKeyString() const { return KeyString; }


protected:
	 
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "KeyString")
	FString KeyString;

public:	
	 
	virtual void Tick(float DeltaTime) override;

};
