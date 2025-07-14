#include "Components/FadeComponent.h"


UFadeComponent::UFadeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	UpdateInterval = 0.01f;
}

void UFadeComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if (!Owner) return;
	RandomizeProperties();
	GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &UFadeComponent::Fade, UpdateInterval, true);
	
}

void UFadeComponent::Fade()
{

	
}

void UFadeComponent::RandomizeProperties()
{
	VisibleDuration = FMath::RandRange(1.0f, 2.0f);
	HiddenDuration = FMath::RandRange(1.0f, 2.0f);
	bIsVisible = FMath::RandBool();
}


