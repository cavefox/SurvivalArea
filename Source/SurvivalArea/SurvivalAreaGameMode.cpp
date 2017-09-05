// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SurvivalAreaGameMode.h"
#include "SurvivalAreaHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASurvivalAreaGameMode::ASurvivalAreaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASurvivalAreaHUD::StaticClass();
}
