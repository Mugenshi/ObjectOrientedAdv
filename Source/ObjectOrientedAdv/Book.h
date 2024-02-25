// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Book.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ABook : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABook();

	UPROPERTY(EditAnywhere)
	FString content;

	UPROPERTY(EditAnywhere)
	FString title;

	UPROPERTY(EditAnywhere)
	FString author;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Book")
	FString get_content();
	UFUNCTION(BlueprintCallable, Category = "Book")
	FString get_title();
	UFUNCTION(BlueprintCallable, Category = "Book")
	FString get_author();

};
