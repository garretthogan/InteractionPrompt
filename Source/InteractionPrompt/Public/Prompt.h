// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prompt.generated.h"

UCLASS()
class INTERACTIONPROMPT_API APrompt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APrompt();

	UPROPERTY(EditAnywhere, Category = "Prompt")
	FText Prompt;

	UPROPERTY(VisibleAnywhere, Category = "Prompt")
	class UBoxComponent* PromptTrigger;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void HandleInteraction(class AController* InteractionInstigator);

	UFUNCTION(BlueprintImplementableEvent, Category = "Prompt")
	void OnInteract(class AController* InteractInstigator);
};
