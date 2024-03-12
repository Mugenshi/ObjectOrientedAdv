
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
	// Sets default values for this character's properties
	ANPC();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	FString get_name();

protected:

	UPROPERTY(EditAnywhere, Category = "attribute")
	FString name;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* Tree;

};