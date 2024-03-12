// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CarSale.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ACarSale : public AActor
{
private:
	GENERATED_BODY()

	UPROPERTY()
	int price;

public:
	ACarSale();

	UFUNCTION(BlueprintCallable, Category = "CarSale")
	int get_price() { return price; }

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
