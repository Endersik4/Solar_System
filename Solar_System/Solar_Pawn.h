// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Solar_Pawn.generated.h"

UCLASS()
class SOLAR_SYSTEM_API ASolar_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASolar_Pawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UStaticMeshComponent* Klocek;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UStaticMeshComponent* Klocek2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyFadeUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyZmianaKameryNaPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Nazwa_Planety_Pawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyClick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* PlanetaCast;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HitCursor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzySpriteRel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int JakaSzybkosc = 5; //1 - stop, 2 - 1s, 3 - 60s, 4 - 1h, 5 - 24h, 6 - 7d, 7 - 1msc, 8 - rok;

	UFUNCTION(BlueprintCallable)
		void SkalaPlanet(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int JakaPlaneta = 1; //1 - uklad_s, 2 - slonce, 3 - merkury, 4 - wenus, 5 - ziemia, 6 - mars, 7 - jowisz, 8 - saturn, 9 - uran, 10 - neptun;

	UFUNCTION(BlueprintCallable)
		void ZmianaPlanety();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CzyRobicSkale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Slonce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Merkury;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Wenus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Ziemia;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Mars;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Jowisz;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Saturn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Uran;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlanety* Neptum;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "ViewTarget")
		class APlanety* ViewTarget = nullptr;
	UPROPERTY(EditAnywhere, Category = "ViewTarget")
		float BlendTime = 1.0f;

private:
	void Length(float Axis);
	void Turn(float Axis);
	void LookUp(float Axis);

	void ClickTrue();
	void ClickFalse();
	bool bClick;
	bool bClickBack;
	void ClickReleased();

	TArray<AActor*> Planets;
	bool Jedna;

	void ClickPlanet();

	bool CzyUI;
	
	APlayerController* PC;

	void CzekanieNaZmianePC();

	bool PatrzenieNaSlonce;
	float SzybkoscKameryYaw;
	float SzybkoscKameryPitch;
	bool CzyPlynnaKamera;
	FRotator InformacjeSzybkosci;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
