// Fill out your copyright notice in the Description page of Project Settings.

#include "grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
Ugrabber::Ugrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Ugrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Error, TEXT("grabber"));
}


// Called every frame
void Ugrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(position, rotation);
	endline = position + rotation.Vector() * reach;

	GetWorld()->LineTraceSingleByObjectType(hit, position, endline, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),FCollisionQueryParams(FName(TEXT("")),false,GetOwner()));
	
	AActor* target = hit.GetActor();
	if (target)
	{
		UE_LOG(LogTemp, Error, TEXT("hit: %s"), *target->GetName());
	}
}

