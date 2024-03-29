// SpecialNPC.h

#pragma once

#include "CoreMinimal.h"
#include "NPC.h"
#include "SpecialNPC.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ASpecialNPC : public ANPC
{
    GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "attribute")
    FString last_name;
    
public:
    ASpecialNPC();


    UFUNCTION(BlueprintCallable, Category = "NPC")
    FString get_last_name();
};
