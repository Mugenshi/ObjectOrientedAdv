// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ATM.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API AATM : public AStaticMeshActor
{
public:
	AATM();

	UFUNCTION(BlueprintCallable)
	void SetMoneyATM(int Money);

	UFUNCTION(BlueprintCallable)
	int GetMoneyATM();

	UFUNCTION(BlueprintCallable)
	void DeductMoneyATM(int Money);

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATM")
	// FString IsSuccess;

	// UFUNCTION()
	// virtual FString GetKeyString() const { return DesiredKey; }

private:
	UPROPERTY()
	int MoneyATM;

	// UPROPERTY()
	// FString DesiredKey;

	GENERATED_BODY()
	
};
