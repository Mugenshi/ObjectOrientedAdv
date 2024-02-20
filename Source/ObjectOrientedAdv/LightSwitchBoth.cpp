// Fill out your copyright notice in the Description page of Project Settings.

#include "LightSwitchBoth.h"
#include "ObjectOrientedAdv.h"

ALightSwitchBoth::ALightSwitchBoth()
    {
        test_encapsulation = 3500.0f;

        DesiredIntensity = 3000.0f;

        PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
        PointLight1->Intensity = DesiredIntensity;

        Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
        Sphere1->InitSphereRadius(250.0f);
        Sphere1->SetupAttachment(RootComponent);

        Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchBoth::OnOverlapBegin);       // set up a notification for when this component overlaps something
        Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchBoth::OnOverlapEnd);       // set up a notification for when this component overlaps something
    }

void ALightSwitchBoth::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchBoth::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchBoth::ToggleLight()
{
	PointLight1->ToggleVisibility();
}

float ALightSwitchBoth::GetTestEncapsulation()
{
    return test_encapsulation;
}