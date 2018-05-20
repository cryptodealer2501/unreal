// Fill out your copyright notice in the Description page of Project Settings.

#include "opendoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
Uopendoor::Uopendoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uopendoor::BeginPlay()
{
	Super::BeginPlay();
	if (!pressureplate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s no triggervolume"), *GetOwner()->GetName());
	}
}

// Called every frame
void Uopendoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (totalmass() > 50.0f)
	{
		open.Broadcast();
	}
	else
	{
		close.Broadcast();
	}
	
}

float Uopendoor::totalmass()
{
	TArray<AActor*> actors;
	float mass = 0.0f;
	if (!pressureplate) { return mass; }
	pressureplate->GetOverlappingActors(actors);
	for (auto actor : actors)
	{
		mass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return mass;
}
