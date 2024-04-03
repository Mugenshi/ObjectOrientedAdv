#pragma once

#include "CoreMinimal.h"
#include "SpecialNPC.h"
#include "IHNPC.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API AIHNPC : public ASpecialNPC
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "attribute") // Changed 'category' to 'Category'
	FString hobbie;

public:
	AIHNPC();

	UFUNCTION(BlueprintCallable, Category = "NPC") // Changed 'category' to 'Category'
	FString get_hobbie();	
	
};
