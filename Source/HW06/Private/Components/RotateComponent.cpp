#include "Components/RotateComponent.h"

URotateComponent::URotateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	UpdateInterval = 0.01f;
}

void URotateComponent::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!Owner) return;
	RandomizeProperties();
	GetWorld()->GetTimerManager().SetTimer(RotationTimerHandle, this, &URotateComponent::UpdateRotation, UpdateInterval, true);
	
}

void URotateComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	UWorld* World = GetWorld();
	if (World && RotationTimerHandle.IsValid())
	{
		World->GetTimerManager().ClearTimer(RotationTimerHandle);
	}
}

void URotateComponent::UpdateRotation()
{
	Owner->AddActorLocalRotation(RotateSpeed * UpdateInterval);
}

void URotateComponent::RandomizeProperties()
{
	RotateSpeed = FRotator(0.0f, FMath::FRandRange(MinSpeed, MaxSpeed), 0.0f);
}



