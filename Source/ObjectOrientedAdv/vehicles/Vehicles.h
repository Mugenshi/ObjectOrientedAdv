// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Vehicles.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UVehicles : public UInterface
{
	GENERATED_BODY()
};

class IVehicles
{
	GENERATED_BODY()



public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Vehicles")
	float GetSpeed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Vehicles")
	float GetWeight();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Vehicles")
	int GetYear();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Vehicles")
	int GetSeats();
};