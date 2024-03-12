// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfHelpBook.h"

ASelfHelpBook::ASelfHelpBook()
{
    PrimaryActorTick.bCanEverTick = false;

    Genre = "Self Help";
}

void ASelfHelpBook::SetFocusArea(FString NewFocusArea)
{
    FocusArea = NewFocusArea;
}

void ASelfHelpBook::SetTargetAudience(FString NewTargetAudience)
{
    TargetAudience = NewTargetAudience;
}

void ASelfHelpBook::SetIsBestSeller(bool NewIsBestSeller)
{
    IsBestSeller = NewIsBestSeller;
}

FString ASelfHelpBook::GetFocusArea() const
{
    return FocusArea;
}

FString ASelfHelpBook::GetTargetAudience() const
{
    return TargetAudience;
}

bool ASelfHelpBook::GetIsBestSeller() const
{
    return IsBestSeller;
}

FString ASelfHelpBook::GetTitle() const
{
    return Title;
}

FString ASelfHelpBook::GetAuthor() const
{
    return Author;
}

FString ASelfHelpBook::GetContent() const
{
    return Content;
}

void ASelfHelpBook::SetTitle(FString NewTitle)
{
    Title = NewTitle;
}

void ASelfHelpBook::SetAuthor(FString NewAuthor)
{
    Author = NewAuthor;
}

void ASelfHelpBook::SetContent(FString NewContent)
{
    Content = NewContent;
}

void ASelfHelpBook::SetGenre(FString NewGenre)
{
    Genre = NewGenre;
}

FString ASelfHelpBook::GetGenre() const
{
    return Genre;
}

