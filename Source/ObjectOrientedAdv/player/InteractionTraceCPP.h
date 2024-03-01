// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "InteractionTraceCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBJECTORIENTEDADV_API UInteractionTraceCPP : public UActorComponent
{
private:
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionTraceCPP();

	// UFUNCTION(BlueprintCallable, Category = "Interaction")
	// void Trace();

	// UFUNCTION(BlueprintCallable, Category = "Interaction")
	// void TraceInteractionArea();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InteractDuration;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
