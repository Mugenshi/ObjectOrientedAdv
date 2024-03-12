// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "TV.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ATV : public AActor
{
private:
	GENERATED_BODY()

	UPROPERTY()
	int price;
	
public:	
	// Sets default values for this actor's properties
	ATV();

	UFUNCTION(BlueprintCallable, Category = "TV")
	int get_price() { return price; }

protected:
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

};
