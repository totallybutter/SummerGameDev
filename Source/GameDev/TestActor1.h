// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor1.generated.h"

UCLASS()
class GAMEDEV_API ATestActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor1();

	/*
		EditAnywhere: The property is visible in the editor and can be modified in the editor.
		BlueprintReadWrite: The property is visible in the editor and can be modified in the editor.
		Transient: The property is not saved to disk.
		BUF: The property is a bitfield.
		Category: The category of the property in the editor. This is used to group properties together in the editor.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Test") int32 value1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Test") int32 value2;
	
	UFUNCTION(BlueprintCallable, Category = "Test") int32 Add(int32 valueA, int32 valueB);
	UFUNCTION(BlueprintImplementableEvent, Category = "Test") void OnAddBlueprint(int32 valueA, int32 valueB, int32 result);

	// Do not directly implement this function with the exact name in the .cpp file
	// Add the _Implementation suffix to the function name before implementing it
	UFUNCTION(BlueprintNativeEvent, Category = "Test") void OnAddNative(int32 valueA, int32 valueB, int32 result);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
