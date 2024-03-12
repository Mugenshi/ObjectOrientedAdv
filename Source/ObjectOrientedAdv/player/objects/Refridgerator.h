// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "Refridgerator.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ARefridgerator : public AActor
{
private:
	GENERATED_BODY()

	UPROPERTY()
	int price;

public:
	ARefridgerator();

	UFUNCTION(BlueprintCallable, Category = "Refrigerator")
	int get_price() { return price; }

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
