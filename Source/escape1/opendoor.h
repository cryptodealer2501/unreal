// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Components/PrimitiveComponent.h"
#include "opendoor.generated.h"


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

	void opendoor();
	void closedoor();
	float totalmass();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private:
	UPROPERTY(VisibleAnywhere)
		int32 Angle = 90;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* pressureplate;

	UPROPERTY(EditAn)
		float delay = 1.0f;

	float time;
	int32 dev = 1 / 120;
};
