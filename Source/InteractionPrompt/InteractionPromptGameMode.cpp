// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "InteractionPromptGameMode.h"
#include "InteractionPromptHUD.h"
#include "InteractionPromptCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInteractionPromptGameMode::AInteractionPromptGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AInteractionPromptHUD::StaticClass();
}
