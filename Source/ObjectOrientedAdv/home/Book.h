// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Book.generated.h"

UCLASS(Blueprintable)
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
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Book")
	FString get_content();
	UFUNCTION(BlueprintCallable, Category = "Book")
	FString get_title();
	UFUNCTION(BlueprintCallable, Category = "Book")
	FString get_author();

};
