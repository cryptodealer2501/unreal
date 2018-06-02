// Fill out your copyright notice in the Description page of Project Settings.

#include "mover.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"

// Sets default values for this component's properties
Umover::Umover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Umover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Umover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	g = GetOwner()->GetActorLocation() - player->GetActorLocation();
	FVector2D cood(g.X, g.Y);
	t = 1 + ((100 - ((cood.Size() / 500) * 100)) / 38);
	if (g.Size() < 500.0f && t<2.8f)
	{
		GetOwner()->SetActorScale3D(FVector(1, 1, t));
	}
	else if (t>=2.8f)
	{
		GetOwner()->SetActorScale3D(FVector(1, 1, 2.8));
	}
	else
	{
		GetOwner()->SetActorScale3D(FVector(1, 1, 1));
	}
	
}

