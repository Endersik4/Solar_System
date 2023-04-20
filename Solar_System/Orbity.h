// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Orbity.generated.h"

UCLASS()
class SOLAR_SYSTEM_API AOrbity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrbity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Szybkosc_Rotacji;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Orbita;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Nazwa_Orbity;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
