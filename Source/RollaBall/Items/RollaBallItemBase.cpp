// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallItemBase.h"
#include "RollaBall/Game/RollaBallPlayer.h"
#include "RollaBall/Game/RollaBallGameModeBase.h"

// Sets default values
ARollaBallItemBase::ARollaBallItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Components - Before this step they won't exist on our Actor, they've only been defined.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	RootComponent = Mesh;

	// Bindings
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollaBallItemBase::OverlapBegin);
}

// Called when the game starts or when spawned
void ARollaBallItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollaBallItemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ARollaBallPlayer>(OtherActor) != nullptr)
	{
		Collected();
	}
}

void ARollaBallItemBase::Collected_Implementation()
{
	// Get GameMode.
	ARollaBallGameModeBase* GameMode = Cast<ARollaBallGameModeBase>(GetWorld()->GetAuthGameMode());

	// Check if cast has been successful.
	if (GameMode)
	{
		// Update gamemode to have Item Collected.
		GameMode->ItemCollected();
	}
}


