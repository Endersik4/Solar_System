// Fill out your copyright notice in the Description page of Project Settings.


#include "Earth_Planety.h"

// Sets default values
AEarth_Planety::AEarth_Planety()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LiniaMoon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LiniaMoon"));
	LiniaMoon->bHiddenInGame = true;
	LiniaMoon->SetupAttachment(Planeta);

	PlanetaMoon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlanetaMoon"));
	PlanetaMoon->SetupAttachment(LiniaMoon);
}

// Called when the game starts or when spawned
void AEarth_Planety::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEarth_Planety::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotacja_Poczatkowa_Moon = LiniaMoon->GetRelativeRotation();
	LiniaMoon->SetRelativeRotation(Rotacja_Poczatkowa_Moon + FRotator(0, Szybkosc_Rotacji_Linii_Moon, 0));

	if (Szybkosc_Rotacji_Planety_Moon != 0.f)
	{
		Rotacja_Poczatkowa_Planeta_Moon = PlanetaMoon->GetRelativeRotation();
		PlanetaMoon->SetRelativeRotation(Rotacja_Poczatkowa_Planeta_Moon + FRotator(0, Szybkosc_Rotacji_Planety_Moon, 0));
	}
}