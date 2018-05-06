// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE1_API Ugrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Ugrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void bindinput();
	void findhandle();
	void grab();
	void release();
	FHitResult raycast();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float reach = 250.0f;

	FRotator rotation;
	FVector position;
	FVector endline;
	FHitResult hit;

	UPhysicsHandleComponent* handle;
	UInputComponent* input;
};
