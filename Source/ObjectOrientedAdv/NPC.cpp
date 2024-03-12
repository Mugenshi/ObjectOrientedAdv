// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "GameFramework/CharacterMovementComponent.h" 


// Sets default values
ANPC::ANPC()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    GetCharacterMovement()->MaxWalkSpeed = 150.f;
    name = "NPC";
}

 
void ANPC::BeginPlay()
{
    Super::BeginPlay();

}

 
void ANPC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

 
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* ANPC::GetBehaviorTree() const
{
    return Tree;
}

FString ANPC::get_name()
{
    return name;
}
