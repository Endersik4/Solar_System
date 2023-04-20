// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Back_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOLAR_SYSTEM_API UBack_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	TArray<AActor*> Ludzik;
protected:

	UFUNCTION()
		void OnBackClick();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* BackBtn;

	virtual void NativeConstruct() override;

	APlayerController* PC;
};
