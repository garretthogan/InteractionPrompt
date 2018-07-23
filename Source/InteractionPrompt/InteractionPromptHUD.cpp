// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "InteractionPromptHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

AInteractionPromptHUD::AInteractionPromptHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

	bShowPrompt = false;
	PromptText = FText();
}


void AInteractionPromptHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );

	float X;
	float Y;
	Canvas->GetCenter(X, Y);

	if (bShowPrompt && !PromptText.IsEmpty())
	{
		FCanvasTextItem TextItem(FVector2D(X - 50, Y), PromptText, Font, FLinearColor::White);
		Canvas->DrawItem(TextItem);
	}
}

void AInteractionPromptHUD::ShowPrompt(FText NewPrompt)
{
	bShowPrompt = true;
	PromptText = NewPrompt;
}

void AInteractionPromptHUD::HidePrompt()
{
	bShowPrompt = false;
	PromptText = FText();
}

