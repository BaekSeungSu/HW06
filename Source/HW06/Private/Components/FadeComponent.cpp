#include "Components/FadeComponent.h"


UFadeComponent::UFadeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UFadeComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if (!Owner) return;
	RandomizeProperties();
	ToggleVisibility(bIsVisible);
	float Delay = bIsVisible ? VisibleDuration : HiddenDuration;
	GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UFadeComponent::Fade, Delay, true);
	
}

void UFadeComponent::Fade()
{
	bIsVisible = !bIsVisible;
	ToggleVisibility(bIsVisible);

	float NextDelay = bIsVisible ? VisibleDuration : HiddenDuration;
	GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UFadeComponent::Fade, NextDelay, true);
	
}

void UFadeComponent::ToggleVisibility(bool Visibility)
{
	Owner->SetActorHiddenInGame(!Visibility);
	Owner->SetActorEnableCollision(Visibility);
}

void UFadeComponent::RandomizeProperties()
{
	VisibleDuration = FMath::RandRange(1.0f, 2.0f);
	HiddenDuration = FMath::RandRange(1.0f, 2.0f);
	bIsVisible = FMath::RandBool();
}


