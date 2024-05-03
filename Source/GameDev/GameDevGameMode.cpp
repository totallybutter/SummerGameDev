// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameDevGameMode.h"
#include "GameDevCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameDevGameMode::AGameDevGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
