// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATMLV4.generated.h"

UCLASS(Abstract)
class OBJECTORIENTEDADV_API AATMLV4 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATMLV4();

	UFUNCTION()
	virtual FString GetDesiredKey() const { return DesiredKey; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATMLV4")
	FString IsSuccess;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATMLV4")
	FString DesiredKey;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
