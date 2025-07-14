#include "Actors/MovingObject.h"

#include "EntitySystem/MovieSceneEntitySystemRunner.h"

AMovingObject::AMovingObject()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(GetRootComponent());
	
	MoveOffset = FVector(0.0f, 0.0f, 0.0f);
}

void AMovingObject::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	EndLocation = StartLocation + MoveOffset;
	InitialDirection = (EndLocation - StartLocation).GetSafeNormal();
	MoveDirection = InitialDirection;
}

void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}


void AMovingObject::Move(float DeltaTime)
{
	float DistanceToMove = MoveSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + MoveDirection * DistanceToMove;
	SetActorLocation(NewLocation);

	FVector VectorToStart = (StartLocation - NewLocation).GetSafeNormal();
	FVector VectorToEnd = (EndLocation - NewLocation).GetSafeNormal();

	if (FVector::DotProduct(VectorToStart, VectorToEnd) > 0.0f)
	{
		FVector TargetLocation = (FVector::DotProduct(MoveDirection, InitialDirection) > 0.0f) ? EndLocation : StartLocation;
		SetActorLocation(TargetLocation);
		MoveDirection = -MoveDirection;
	}
}

