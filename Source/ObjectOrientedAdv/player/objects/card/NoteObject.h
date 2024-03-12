// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoteObject.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ANoteObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANoteObject();

protected:
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

};
