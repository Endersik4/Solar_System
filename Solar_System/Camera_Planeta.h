// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera_Planeta.generated.h"

UCLASS()
class SOLAR_SYSTEM_API ACamera_Planeta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACamera_Planeta();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Linia;


	UPROPERTY(EditAnywhere)
		float Szybkosc_Rotacji_Linii;

	UPROPERTY(EditAnywhere)
		float Szybkosc_Rotacji_Planety;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FRotator Rotacja_Poczatkowa;
	FRotator Rotacja_Poczatkowa_Planeta;

};
