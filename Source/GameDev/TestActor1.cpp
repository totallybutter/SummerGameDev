// Fill out your copyright notice in the Description page of Project Settings.
#include "TestActor1.h"

// Sets default values
ATestActor1::ATestActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	value1 = value2 = 0;
}

// Called when the game starts or when spawned
void ATestActor1::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ATestActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ATestActor1::Add(int32 a, int32 b)
{
	// The first parameter is the log category, the second is the verbosity level, and the third is the message.
	UE_LOG(LogTemp, Warning, TEXT("Add(int,int) Called"));


	OnAddBlueprint(a, b, a + b); // when called, does whatever modules are attached to it in the blueprint.


	OnAddNative(a, b, a + b); // Call the function <func name>_implementation.


	return a + b;
}

void ATestActor1::OnAddNative_Implementation(int32 valueA, int32 valueB, int32 result)
{
	// -1 means that the message will not be removed automatically.
	// 5.f is the time that the message will be displayed in seconds.
	// FColor::Red is the color of the message.
	// FString::Printf is a function that works like printf in C++.
	// The TEXT macro is used to convert the string to a TCHAR.
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, 
		FString::Printf(TEXT("OnAddNative: %d + %d = %d"), valueA, valueB, result));

	// UE_LOG(LogTemp, Warning, TEXT("OnAddNative: %d + %d = %d"), valueA, valueB, result);
}
