// Fill out your copyright notice in the Description page of Project Settings.


#include "Solar_Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Planety.h"
#include "Components/TextRenderComponent.h"

#define wys(ab) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, ab);

// Sets default values
ASolar_Pawn::ASolar_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Klocek = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Klocek"));
	RootComponent = Klocek;

	Klocek2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Klocek2"));
	Klocek2->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Klocek2);


}

// Called when the game starts or when spawned
void ASolar_Pawn::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlanety::StaticClass(), Planets);
	PC = UGameplayStatics::GetPlayerController(this, 0);
	
}

// Called every frame
void ASolar_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bClick == false)
	{
		if (CzyUI == false)
		{
			FHitResult Hit;

			PC->GetHitResultUnderCursor(ECC_WorldDynamic, false, Hit);
			if (Hit.bBlockingHit && Jedna == false && PatrzenieNaSlonce == false && Hit.GetActor()->ActorHasTag("Planeta"))
			{
				PlanetaCast = Cast<APlanety>(Hit.GetActor());
				PlanetaCast->CzyTextVisible = true;
				Jedna = true;
				CzyClick = true;
			}
			else if (Hit.bBlockingHit == false && Jedna == true && PatrzenieNaSlonce == false)
			{
				Jedna = false;
				CzyClick = false;
				for (int i = 0; i != Planets.Num(); i++)
				{
					auto PlanetsCast = Cast<APlanety>(Planets[i]);
					PlanetsCast->CzyTextVisible = false;
				}
			}
		}
		else if (CzyUI == true)
		{
				if (HitCursor == true && bClickBack == true)
				{
					if (PlanetaCast != NULL) PlanetaCast->CzyBack = true;
					FTimerHandle ZmianaPC;
					GetWorldTimerManager().SetTimer(ZmianaPC, this, &ASolar_Pawn::CzekanieNaZmianePC, 0.1f, false, 0.1f);
					bClickBack = false;
					HitCursor = false;
				}
			
		}
	}

	/*if (CzyPlynnaKamera == true)
	{
		if (SzybkoscKameryPitch != 0.f || SzybkoscKameryYaw != 0.f)
		{
			FRotator Rotation_Camera = GetActorRotation();
			if (SzybkoscKameryYaw != 0.f)
			{
				Rotation_Camera.Yaw += SzybkoscKameryYaw;
				if (SzybkoscKameryYaw > 0.05f) SzybkoscKameryYaw -= 0.1f;
				else if (SzybkoscKameryYaw < -0.05f) SzybkoscKameryYaw += 0.1f;
				else SzybkoscKameryYaw = 0;
			}
			if (SzybkoscKameryPitch != 0.f)
			{
				Rotation_Camera.Pitch += SzybkoscKameryPitch;
				if (SzybkoscKameryPitch > 0.09f) SzybkoscKameryPitch -= 0.1f;
				else if (SzybkoscKameryPitch < -0.09f) SzybkoscKameryPitch += 0.1f;
				else SzybkoscKameryPitch = 0;
			}
			SetActorRotation(Rotation_Camera);
		}
		else CzyPlynnaKamera = false;
	}
	*/
	if (CzyRobicSkale == true)
	{
		SkalaPlanet(DeltaTime);
	}
}

void ASolar_Pawn::SkalaPlanet(float DeltaTime)
{

	if (CzySpriteRel == true)
	{
		for (int i = 0; i != Planets.Num(); i++)
		{
			auto PlanetyCast = Cast<APlanety>(Planets[i]);
			if (!PlanetyCast->ActorHasTag("Slonce"))
			{
				if (PlanetyCast->GetActorScale3D() == PlanetyCast->RealnaSkala)
				{
					CzyRobicSkale = false;
					break;
				}
				PlanetyCast->SetActorScale3D(FMath::VInterpTo(PlanetyCast->GetActorScale3D(), PlanetyCast->RealnaSkala, DeltaTime, 5.f));
			}
		}

	}
	else
	{
		for (int i = 0; i != Planets.Num(); i++)
		{
			auto PlanetyCast = Cast<APlanety>(Planets[i]);
			if (!PlanetyCast->ActorHasTag("Slonce"))
			{
				if (PlanetyCast->GetActorScale3D() == PlanetyCast->NierealnaSkala)
				{
					CzyRobicSkale = false;
					break;
				}
				PlanetyCast->SetActorScale3D(FMath::VInterpTo(PlanetyCast->GetActorScale3D(), PlanetyCast->NierealnaSkala, DeltaTime, 5.f));
			}
		}
	}
	
	/*if (CzySpriteRel == true)
	{
		for (int i = 0; i != Planets.Num(); i++)
		{
			auto PlanetyCast = Cast<APlanety>(Planets[i]);
			PlanetyCast->SetActorScale3D(PlanetyCast->RealnaSkala);
		}
		
	}
	else
	{
		for (int i = 0; i != Planets.Num(); i++)
		{
			auto PlanetyCast = Cast<APlanety>(Planets[i]);
			PlanetyCast->SetActorScale3D(PlanetyCast->NierealnaSkala);
		}
		
	}
	*/

}

void ASolar_Pawn::CzekanieNaZmianePC()
{
	CzyZmianaKameryNaPawn = true;
	TArray<AActor*> Ludzik;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASolar_Pawn::StaticClass(), Ludzik);
	PC->SetViewTargetWithBlend(Ludzik[0], BlendTime);
	//RESTART WSZYSTKICH ZMIENNYCH ABY WSYZSTKO DZIALALo
	if (PlanetaCast != NULL)
	{
		PlanetaCast->CzyBack = false;
		PlanetaCast->CzyNajechalBack = false;
	}
	bClick = false;
	bClickBack = false;
	Jedna = false;
	CzyClick = false;
	CzyUI = false;
	CzyFadeUI = false;
}

// Called to bind functionality to input
void ASolar_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("UpLength", this, &ASolar_Pawn::Length);
	PlayerInputComponent->BindAxis("Turn", this, &ASolar_Pawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASolar_Pawn::LookUp);
	
	PlayerInputComponent->BindAction("LeftClickHold", IE_Pressed, this, &ASolar_Pawn::ClickTrue);
	PlayerInputComponent->BindAction("LeftClickHold", IE_Released, this, &ASolar_Pawn::ClickFalse);
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &ASolar_Pawn::ClickPlanet);
	PlayerInputComponent->BindAction("LeftClick", IE_Released, this, &ASolar_Pawn::ClickReleased);
}

void ASolar_Pawn::ClickPlanet()
{
	bClickBack = true;
	if (CzyClick == true && CzyUI == false)
	{
		CzyZmianaKameryNaPawn = false;
		CzyUI = true;
		PlanetaCast->CzyTextVisible = false;
		CzyFadeUI = true;
		Nazwa_Planety_Pawn = PlanetaCast->Nazwa;
		PC->SetViewTargetWithBlend(PlanetaCast, BlendTime);
	}
}

void ASolar_Pawn::ZmianaPlanety()
{
	if (JakaPlaneta != 1)
	{
		CzyZmianaKameryNaPawn = false;
		CzyUI = true;
		CzyFadeUI = true;
		CzyClick = true;
		switch (JakaPlaneta)
		{
		case 1:
		{
			;
		}; break;
		case 2:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Slonce")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 3:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Merkury")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 4:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Wenus")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 5:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Ziemia")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 6:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Mars")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 7:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Jowisz")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 8:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Saturn")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 9:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Uran")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		case 10:
		{
			for (int i = 0; i != Planets.Num(); i++)
			{
				auto Planety = Cast<APlanety>(Planets[i]);
				if (Planety->Nazwa == "Neptune")
				{
					Planety->CzyTextVisible = false;
					Nazwa_Planety_Pawn = Planety->Nazwa;
					PC->SetViewTargetWithBlend(Planety, BlendTime);
				}
			}
		} break;
		default: wys("Blad ze Zmiana planety w C++"); break;
		}
	}
}

void ASolar_Pawn::ClickReleased()
{
	bClickBack = false;
	SzybkoscKameryYaw = InformacjeSzybkosci.Yaw/10.f;
	SzybkoscKameryPitch = InformacjeSzybkosci.Pitch/10.f;
	CzyPlynnaKamera = true;
}

void ASolar_Pawn::Length(float Axis)
{
	FVector Location_Camera = Camera->GetRelativeLocation();
	if (Location_Camera.X >= 3836.f)
	{
		Location_Camera.X += Axis;
		PatrzenieNaSlonce = false;
		Camera->SetRelativeLocation(Location_Camera);
	}
	else if (Axis > 0.f)
	{
		Location_Camera.X += Axis;
		Camera->SetRelativeLocation(Location_Camera);
	}
	else PatrzenieNaSlonce = true;
}

void ASolar_Pawn::Turn(float Axis)
{
	if (bClick == true && CzyClick == false && CzyUI == false)
	{
		FRotator Rotation_Actor = GetActorRotation();
		Rotation_Actor.Yaw += Axis;
		InformacjeSzybkosci.Yaw += Axis;
		SetActorRotation(Rotation_Actor);
	}
}

void ASolar_Pawn::LookUp(float Axis)
{
	if (bClick == true && CzyClick == false && CzyUI == false)
	{
		FRotator Rotation_Actor = GetActorRotation();
		Rotation_Actor.Pitch += Axis;
		InformacjeSzybkosci.Pitch += Axis;
		SetActorRotation(Rotation_Actor);
	}
}

void ASolar_Pawn::ClickTrue()
{
	if (CzyUI == false)
	{
		bClick = true;
		PC->bShowMouseCursor = true;
		SzybkoscKameryYaw = 0;
		SzybkoscKameryPitch = 0;
		CzyPlynnaKamera = false;
		InformacjeSzybkosci = FRotator(0, 0, 0);
	}
}

void ASolar_Pawn::ClickFalse()
{
	bClick = false;
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
}


