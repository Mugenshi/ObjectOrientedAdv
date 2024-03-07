// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_MoveToWithDelay.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API UBTTask_MoveToWithDelay : public UBTTask_MoveTo
{
	GENERATED_BODY()
	
protected:
    // Time to delay in seconds
    UPROPERTY(EditAnywhere, Category = "Delay")
    float DelayTime = 1.0f; // Default delay time is 1 second

	// Timer handle for delay
    FTimerHandle DelayTimerHandle;

public:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
