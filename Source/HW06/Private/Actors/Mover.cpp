#include "Actors/Mover.h"
#include "Components/PathMoverComponent.h"

AMover::AMover() : Super()
{
	PrimaryActorTick.bCanEverTick = false;

	PathMoverComp = CreateDefaultSubobject<UPathMoverComponent>(TEXT("PathMoverComp"));
}

void AMover::BeginPlay()
{
	Super::BeginPlay();
}

void AMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
