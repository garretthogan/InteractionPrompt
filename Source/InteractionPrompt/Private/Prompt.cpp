// Fill out your copyright notice in the Description page of Project Settings.

#include "Prompt.h"
#include "InteractionPrompt.h"
#include "Components/BoxComponent.h"

// Sets default values
APrompt::APrompt()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	PromptTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("PromptTrigger"));
	PromptTrigger->SetCollisionResponseToAllChannels(ECR_Ignore);
	PromptTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PromptTrigger->SetCollisionResponseToChannel(TRACE_CHANNEL_Prompt, ECR_Block);
	PromptTrigger->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APrompt::BeginPlay()
{
	Super::BeginPlay();
	
}

void APrompt::HandleInteraction(class AController* InteractionInstigator)
{
	// Core game logic here

	OnInteract(InteractionInstigator);
}

