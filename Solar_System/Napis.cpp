// Fill out your copyright notice in the Description page of Project Settings.


#include "Napis.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ANapis::ANapis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Nazwa"));

}

// Called when the game starts or when spawned
void ANapis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANapis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

