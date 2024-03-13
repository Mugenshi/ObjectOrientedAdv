// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Animals.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UAnimals : public UInterface
{
	GENERATED_BODY()
};

class IAnimals
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animals")
	void DecideNextAction(bool SkipDelay);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animals")
	void RandomRoam();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animals")
	FString GetName();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animals")
	FString GetType();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Animals")
	FString GetSay();
	
};
