// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KotwiczkaPlanet.generated.h"

UCLASS()
class SOLAR_SYSTEM_API AKotwiczkaPlanet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKotwiczkaPlanet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString NazwaOrbityPlanety;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
