// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToWithDelay.h"
#include "TimerManager.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_MoveToWithDelay::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // Call the parent's execute task first
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

    // Get the AI controller and blackboard
    AAIController* AIController = OwnerComp.GetAIOwner();
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

    // Check if AI controller and blackboard are valid
    if (AIController && BlackboardComp)
    {
        // Get the destination from blackboard
        FVector Destination = BlackboardComp->GetValueAsVector(GetSelectedBlackboardKey());

        // Delay before moving
        OwnerComp.GetOwner()->GetWorldTimerManager().SetTimer(
            DelayTimerHandle,
            [this, &OwnerComp, AIController, Destination]()
            {
                // Move to the destination
                AIController->MoveToLocation(Destination);
            },
            DelayTime,
            false // Do not loop
        );
    }

    return Result;
}
