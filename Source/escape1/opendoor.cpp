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
	FRotator g(0, 90, 0);
}

void Uopendoor::opendoor()
{
	GetOwner()->SetActorRotation(FRotator(0, 90, 0));
	
}

void Uopendoor::closedoor()
{
	GetOwner()->SetActorRotation(FRotator(0, 0, 0));
}

// Called every frame
void Uopendoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (totalmass() > 50.0f)
	{
		if (GetOwner()->GetActorRotation().Yaw < 90)
		{
			GetOwner()->AddActorLocalRotation(FRotator(0, 180* DeltaTime, 0));
			UE_LOG(LogTemp, Warning, TEXT(""));
		}
		time = GetWorld()->GetTimeSeconds();
	}
	
	if ((GetWorld()->GetTimeSeconds()) - time > delay)
	{
		if (GetOwner()->GetActorRotation().Yaw > 0)
		{
			GetOwner()->AddActorLocalRotation(FRotator(0, -180* DeltaTime, 0));
		}
	}
}

float Uopendoor::totalmass()
{
	TArray<AActor*> actors;
	float mass = 0.0f;
	pressureplate->GetOverlappingActors(actors);
	for (auto actor : actors)
	{
		mass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return mass;
}
