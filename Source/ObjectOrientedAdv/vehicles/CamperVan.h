// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehicles.h"
#include "CamperVan.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ACamperVan : public AActor, public IVehicles
{
	GENERATED_BODY()

	UPROPERTY()
	float Speed;

	UPROPERTY()
	float Weight;
	
public:	
	// Sets default values for this actor's properties
	ACamperVan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetSpeed_Implementation() override;
	float GetWeight_Implementation() override;

};
