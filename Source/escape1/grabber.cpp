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

	findhandle();
	bindinput();
}

void Ugrabber::bindinput()
{
	input = GetOwner()->FindComponentByClass<UInputComponent>();

	if (input)
	{
		input->BindAction("grab", IE_Pressed, this, &Ugrabber::grab);
		input->BindAction("grab", IE_Released, this, &Ugrabber::release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s no inputcomponent found"), *GetOwner()->GetName());
	}
}

void Ugrabber::findhandle()
{
	handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (handle)
	{

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s no handle found"), *GetOwner()->GetName());
	}
}

void Ugrabber::grab()
{
	UE_LOG(LogTemp, Warning, TEXT("grab"));
	FHitResult target = raycast();
	UPrimitiveComponent* component = target.GetComponent();

	if (target.GetActor())
	{
		handle->GrabComponent(component, NAME_None, component->GetOwner()->GetActorLocation(), true);
		UE_LOG(LogTemp, Warning, TEXT("grabbed"));
	}

}

void Ugrabber::release()
{
	UE_LOG(LogTemp, Warning, TEXT("release"));
	handle->ReleaseComponent();
}

FHitResult Ugrabber::raycast()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(position, rotation);
	endline = position + rotation.Vector() * reach;

	GetWorld()->LineTraceSingleByObjectType(hit, 
											position,
											endline,
											FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
											FCollisionQueryParams(FName(TEXT("")),
																  false,
																  GetOwner()));
	if (hit.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("hit %s"), *hit.GetActor()->GetName());
	}
	return hit;
}

// Called every frame
void Ugrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(position, rotation);
	endline = position + rotation.Vector() * reach;

	if (handle->GrabbedComponent)
	{
		handle->SetTargetLocation(endline);
	}
}

