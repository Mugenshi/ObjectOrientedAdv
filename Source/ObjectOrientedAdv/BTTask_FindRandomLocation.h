// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API UBTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UBTTask_FindRandomLocation(const FObjectInitializer& ObjectInitializer); // Fixed the constructor signature
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true")) // Corrected the spelling of Category
	float SearchRadius = 3000.f;
	
};
