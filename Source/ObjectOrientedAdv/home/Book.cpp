// Fill out your copyright notice in the Description page of Project Settings.


#include "Book.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ABook::ABook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	title = "Harry Potter";
	author = "JK ";
	content = "none";

}

// Called when the game starts or when spawned
void ABook::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString ABook::get_author() 
{
	return author;
}

FString ABook::get_content() 
{
	return content;
}

FString ABook::get_title()
{
	return title;
}
