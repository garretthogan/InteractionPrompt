// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Prompt.h"
#include "LimitedUsePrompt.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIONPROMPT_API ALimitedUsePrompt : public APrompt
{
	GENERATED_BODY()
	
	
public:

	ALimitedUsePrompt();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Prompt")
	int32 NumberOfUses;

	virtual void HandleInteraction(class AController* InteractionInstigator) override;
};
