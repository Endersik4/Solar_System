// Fill out your copyright notice in the Description page of Project Settings.


#include "Back_UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Solar_Pawn.h"

void UBack_UserWidget::NativeConstruct()
{
	if (BackBtn)
	{
		BackBtn->OnClicked.AddDynamic(this, &UBack_UserWidget::OnBackClick);
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASolar_Pawn::StaticClass(), Ludzik);
	PC = UGameplayStatics::GetPlayerController(this, 0);
}

void UBack_UserWidget::OnBackClick()
{
	UE_LOG(LogTemp, Warning, TEXT("ras"));
}