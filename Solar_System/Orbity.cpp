// Fill out your copyright notice in the Description page of Project Settings.


#include "Orbity.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AOrbity::AOrbity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Orbita = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Orbita"));
	Orbita->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AOrbity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorRotation(GetActorRotation() + FRotator(0, (Szybkosc_Rotacji * DeltaTime), 0));
}

