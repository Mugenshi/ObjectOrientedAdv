// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BookAbstract.h"
#include "SelfHelpBook.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API ASelfHelpBook : public ABookAbstract
{
	GENERATED_BODY()

public:
	ASelfHelpBook();

	// Setters

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual void SetGenre(FString NewGenre) override;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual void SetTitle(FString NewTitle) override;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual void SetAuthor(FString NewAuthor) override;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual void SetContent(FString NewContent) override;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	void SetFocusArea(FString NewFocusArea);

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	void SetTargetAudience(FString NewTargetAudience);

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	void SetIsBestSeller(bool NewIsBestSeller);

	// Getters
	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	FString GetFocusArea() const;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	FString GetTargetAudience() const;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	bool GetIsBestSeller() const;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	FString GetTitle() const;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual FString GetAuthor() const;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual FString GetContent() const;

	UFUNCTION(BlueprintCallable, Category = "SelfHelpBook")
	virtual FString GetGenre() const;

private:

	UPROPERTY()
	FString FocusArea;

	UPROPERTY()
	FString TargetAudience;

	UPROPERTY()
	bool IsBestSeller;
	
};
