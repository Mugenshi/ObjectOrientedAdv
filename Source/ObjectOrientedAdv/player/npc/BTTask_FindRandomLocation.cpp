#include "BTTask_FindRandomLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC_AIController.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation(const FObjectInitializer& ObjectInitializer)
{
    NodeName = "Find Random Location In NavMesh";
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) // Fixed the function signature
{
    // Get AI controller and its NPC
    if (auto* const Cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner()))
    {
        if (auto* const NPC = Cont->GetPawn())
        {
            // Obtain NPC location to use as an origin
            const FVector Origin = NPC->GetActorLocation();

            // Get the navigation system and generate a random location
            if (UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld()))// Corrected the usage of UNavigationSystemV1
            {
                FNavLocation Loc;
                if (NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, Loc))
                {
                    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location); // Corrected the spelling of Location
                }

                // Finish with success
                FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
                return EBTNodeResult::Succeeded;
            }
        }
    }

    return EBTNodeResult::Failed;
}
