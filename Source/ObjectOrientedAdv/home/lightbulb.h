// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "lightbulb.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API Alightbulb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Alightbulb();

protected:
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

};
