// Fill out your copyright notice in the Description page of Project Settings.


#include "BobbingActorComponent.h"

// Sets default values for this component's properties
UBobbingActorComponent::UBobbingActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	UE_LOG(LogTemp, Warning, TEXT("UBobbingActorComponent::UBobbingActorComponent"));

}


// Called when the game starts
void UBobbingActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("UBobbingActorComponent::BeginPlay"));

	InitialHeight = GetOwner()->GetActorLocation().Z;
	Timer = 0;
}


// Called every frame
void UBobbingActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	// UE_LOG(LogTemp, Warning, TEXT("UBobbingActorComponent::TickComponent"));

	Timer += DeltaTime;

	// Make this thing bob up and down, based on an Amplitude and Frequency.
	FVector Location = GetOwner()->GetActorLocation();
	// y = y_0 + A * sin(bx)
	float NewZValue = InitialHeight + Amplitude * FMath::Sin(Frequency * Timer);
	FVector NewLocation{ Location.X, Location.Y, NewZValue };
	GetOwner()->SetActorLocation(NewLocation);

	// Inspired from: https://www.youtube.com/watch?v=sWSbqAAv8Gk
	// FVector Rotation = RotationAxis * RotationSpeed * DeltaTime;
	// GetOwner()->AddActorLocalRotation(FQuat::MakeFromEuler(Rotation));

	// Make this thing rotate around a given axis at a fixed speed.
	FVector RotationAxisNormalized(RotationAxis.GetSafeNormal());
	float RotationAmount = Timer;
	GetOwner()->SetActorRotation(FQuat::MakeFromRotationVector(RotationAxisNormalized * RotationAmount));
}
