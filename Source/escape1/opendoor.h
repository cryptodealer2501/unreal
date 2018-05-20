// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Components/PrimitiveComponent.h"
#include "opendoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fdoor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE1_API Uopendoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Uopendoor();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float totalmass();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		Fdoor open;

	UPROPERTY(BlueprintAssignable)
		Fdoor close;
private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* pressureplate;
};
