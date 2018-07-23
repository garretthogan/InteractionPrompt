// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InteractionPromptHUD.generated.h"

UCLASS()
class AInteractionPromptHUD : public AHUD
{
	GENERATED_BODY()

public:
	AInteractionPromptHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	bool bShowPrompt;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	class UFont* Font;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	FText PromptText;

	void ShowPrompt(FText NewPrompt);

	void HidePrompt();

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
};

