// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "RollaBall/Items/RollaBallItemBase.h"

void ARollaBallGameModeBase::BeginPlay()
{
	TArray<AActor*> Items;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARollaBallItemBase::StaticClass(), Items);
	ItemsInLevel = Items.Num();


}

void ARollaBallGameModeBase::UpdateItemText()
{

}

void ARollaBallGameModeBase::ItemCollected()
{
	ItemsCollected++;
}