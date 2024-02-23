// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "LightSwitchBoth.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ALightSwitchBoth : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float test_encapsulation;
	
public:
	/** point light component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Switch Components")
	class UPointLightComponent* PointLight1;

	/** sphere component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Switch Components")
	class USphereComponent* Sphere1;

	ALightSwitchBoth();

	/** called when something enters the sphere component */
	UFUNCTION(BlueprintNativeEvent, Category="Switch Functions")
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION(BlueprintNativeEvent, Category="Switch Functions")
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Toggles the light component's visibility*/
	UFUNCTION()
	void ToggleLight();

	/** the desired intensity for the light */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
	float DesiredIntensity;

	UFUNCTION(BlueprintCallable, Category="Switch Functions")
	float GetTestEncapsulation();

};
