// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planety.generated.h"

UCLASS()
class SOLAR_SYSTEM_API APlanety : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanety();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Nazwa;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Planeta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyNajechalBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyTextVisible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Szybkosc_Rotacji_Linii;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Szybkosc_Rotacji_Planety;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ASolar_Pawn* Ludzik;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ANapis* Tekst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> Predkosc_Lini_w_czasie; //0 - 1s, 1 - 60s, 2 - 1h, 3 - 24h, 4 - 7d, 5 - 1msc, 6 - rok;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> Predkosc_Planety_w_czasie; //0 - 1s, 1 - 60s, 2 - 1h, 3 - 24h, 4 - 7d, 5 - 1msc, 6 - rok;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Linia;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector RealnaSkala;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector NierealnaSkala;

private:
	FRotator Rotacja_Poczatkowa;
	FRotator Rotacja_Poczatkowa_Planeta;
	TArray<AActor*> Kotwiczki;
	class AKotwiczkaPlanet* KotwiczkaCast;
	bool CzyCast;


};
