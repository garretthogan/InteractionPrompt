// Fill out your copyright notice in the Description page of Project Settings.

#include "LimitedUsePrompt.h"




ALimitedUsePrompt::ALimitedUsePrompt()
{
	NumberOfUses = 1;
}

void ALimitedUsePrompt::HandleInteraction(class AController* InteractionInstigator)
{
	NumberOfUses--;
	Super::HandleInteraction(InteractionInstigator);
	if (NumberOfUses <= 0)
	{
		Destroy();
	}
}
