
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "NPC.generated.h"


UCLASS()
class OBJECTORIENTEDADV_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	 
	ANPC();

	 
	virtual void Tick(float DeltaTime) override;

	 
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	FString get_name();

protected:

	UPROPERTY(EditAnywhere, Category = "attribute")
	FString name;
	 
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* Tree;

};