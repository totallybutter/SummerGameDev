// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BobbingActorComponent.generated.h"


UCLASS(ClassGroup = (ACustom), meta = (BlueprintSpawnableComponent))
class GAMEDEV_API UBobbingActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBobbingActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	FVector RotationAxis;

	//UPROPERTY(EditAnywhere)
	//float RotationSpeed;

	float InitialHeight;
	float Timer;

	UPROPERTY(EditAnywhere)
	float Amplitude;

	UPROPERTY(EditAnywhere)
	float Frequency;
};
