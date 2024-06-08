// Fill out your copyright notice in the Description page of Project Settings.
#include "TestActor1.h"

// Sets default values
ATestActor1::ATestActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	value1 = value2 = 0; addKey = EKeys::P;
}

// Called when the game starts or when spawned
void ATestActor1::BeginPlay()
{
	Super::BeginPlay();

	AddTwoValues();
}

// Called every frame
void ATestActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// if player presses the 'P' key (no holding down), the values will be added again.
	if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(addKey))
	{
		AddTwoValues();
		FString keyName = addKey.ToString();
		UE_LOG(LogTemp, Display, TEXT("Key %s was pressed."), *keyName);
		// The following code will print the key name to the screen.
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green,
			FString::Printf(TEXT("Key %s was pressed."), *keyName));
	}
}

int32 ATestActor1::AddTwoValues()
{
	// The first parameter is the log category, the second is the verbosity level, and the third is the message.
	UE_LOG(LogTemp, Warning, TEXT("Add: %d + %d = %d"), value1, value2, value1 + value2);

	// value1 and value2's values are taken from the editor.
	// when called, does whatever modules are attached to it in the blueprint.
	OnAddBlueprint(value1, value2, value1 + value2);

	// Call the function <func name>_implementation.
	
	OnAddNative(value1, value2, value1 + value2); 

	return value1 + value2;
}

// Keep in mind that should this function be overriden in a blueprint, 
// the blueprint's implementation will be called with whatever values are set inside the blueprint.
// Make the necessary node connections then, to ensure that the correct values are passed.
void ATestActor1::OnAddNative_Implementation(int32 valueA, int32 valueB, int32 result)
{
	// -1 means that the message will not be removed automatically.
	// 5.f is the time that the message will be displayed in seconds.
	// FColor::Red is the color of the message.
	// FString::Printf is a function that works like printf in C++.
	// The TEXT macro is used to convert the string to a TCHAR.
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, 
		FString::Printf(TEXT("OnAddNative: %d + %d = %d"), valueA, valueB, result));

	// UE_LOG(LogTemp, Warning, TEXT("OnAddNative: %d + %d = %d"), valueA, valueB, result);
}
