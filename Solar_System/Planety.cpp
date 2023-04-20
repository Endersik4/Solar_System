// Fill out your copyright notice in the Description page of Project Settings.


#include "Planety.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Camera/CameraComponent.h"
#include "KotwiczkaPlanet.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Solar_Pawn.h"

// Sets default values
APlanety::APlanety()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Linia = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Linia"));
	RootComponent = Linia;
	Linia->bHiddenInGame = true;

	Planeta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Planeta"));
	Planeta->SetupAttachment(RootComponent);

	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Nazwa"));
	Text->SetVisibility(false);
	Text->SetHorizontalAlignment(EHTA_Center);
	Text->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	//UI = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("UI"));
	//UI->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlanety::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AKotwiczkaPlanet::StaticClass(), Kotwiczki);
	for (int i = 0; i != Kotwiczki.Num(); i++)
	{
		KotwiczkaCast = Cast<AKotwiczkaPlanet>(Kotwiczki[i]);
		if (KotwiczkaCast->NazwaOrbityPlanety == Nazwa)
		{
			CzyCast = true;
			break;
		}
	}
	
}

// Called every frame
void APlanety::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (Nazwa == "Slonce")
	{
		Rotacja_Poczatkowa = GetActorRotation();
		SetActorRotation(Rotacja_Poczatkowa + FRotator(0, (Szybkosc_Rotacji_Planety * DeltaTime), 0));
	}
	*/
	if (CzyCast == true) SetActorLocation(KotwiczkaCast->GetActorLocation());
	if (Text->IsVisible() == true)
	{
		//FVector PlayerLoc = Ludzik->GetActorLocation();
		//FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), PlayerLoc);
		//FRotator NewRot = FMath::RInterpTo(Text->GetComponentRotation(), PlayerRot, DeltaTime, 2);
	}
	if (Szybkosc_Rotacji_Planety != 0.f)
	{
		Rotacja_Poczatkowa_Planeta = Planeta->GetRelativeRotation();
		Planeta->SetRelativeRotation(Rotacja_Poczatkowa_Planeta + FRotator(0, (Szybkosc_Rotacji_Planety * DeltaTime), 0));
	}
}

