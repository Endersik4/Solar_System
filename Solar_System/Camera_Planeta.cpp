// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera_Planeta.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACamera_Planeta::ACamera_Planeta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Linia = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Linia"));
	RootComponent = Linia;
	Linia->bHiddenInGame = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Linia);
}

// Called when the game starts or when spawned
void ACamera_Planeta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamera_Planeta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotacja_Poczatkowa = GetActorRotation();
	SetActorRotation(Rotacja_Poczatkowa + FRotator(0, Szybkosc_Rotacji_Linii, 0));

	if (Szybkosc_Rotacji_Planety != 0.f)
	{
		Rotacja_Poczatkowa_Planeta = Camera->GetRelativeRotation();
		Camera->SetRelativeRotation(Rotacja_Poczatkowa_Planeta + FRotator(0, Szybkosc_Rotacji_Planety, 0));
	}

}

