#include "Components/PathMoverComponent.h"


UPathMoverComponent::UPathMoverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	UpdateInterval = 0.01f;
	TotalDistance = 0.0f;
}


void UPathMoverComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if (!Owner) return;
	RandomizeProperties();
	GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &UPathMoverComponent::UpdateMovement, UpdateInterval, true);

}

void UPathMoverComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	UWorld* World = GetWorld();
	if (World && MovementTimerHandle.IsValid())
	{
		World->GetTimerManager().ClearTimer(MovementTimerHandle);
	}
}

void UPathMoverComponent::UpdateMovement()
{
	float DistanceToMove = MoveSpeed * UpdateInterval;
	FVector NewLocation = Owner->GetActorLocation() + MoveDirection * DistanceToMove;
	Owner->SetActorLocation(NewLocation);
	TotalDistance += DistanceToMove;
	
	if (TotalDistance >= MoveDistance)
	{
		MoveDirection = -MoveDirection;
		TotalDistance = 0.0f;
		StartLocation = NewLocation;
	}
}

void UPathMoverComponent::RandomizeProperties()
{
	MoveSpeed = FMath::FRandRange(MinSpeed, MaxSpeed);
	MoveDistance = FMath::FRandRange(MinDistance, MaxDistance);
	MoveDirection = FMath::VRand().GetSafeNormal();
	StartLocation = Owner->GetActorLocation();
}
