// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Planety.h"
#include "Earth_Planety.generated.h"

/**
 * 
 */
UCLASS()
class SOLAR_SYSTEM_API AEarth_Planety : public APlanety
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEarth_Planety();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* LiniaMoon;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PlanetaMoon;

	UPROPERTY(EditAnywhere)
		float Szybkosc_Rotacji_Linii_Moon;

	UPROPERTY(EditAnywhere)
		float Szybkosc_Rotacji_Planety_Moon;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FRotator Rotacja_Poczatkowa_Moon;
	FRotator Rotacja_Poczatkowa_Planeta_Moon;
};
