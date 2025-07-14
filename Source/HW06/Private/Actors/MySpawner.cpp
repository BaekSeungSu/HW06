#include "Actors/MySpawner.h"
#include "Components/BoxComponent.h"
#include "Actors/LevelGimmick.h"

AMySpawner::AMySpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	
	SpawningVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningVolume"));
	SetRootComponent(SpawningVolume);
	SpawningVolume->SetHiddenInGame(true);
	SpawningVolume->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SpawnCount = 5;
	MinSpawnDistance = 200.0f;
}

void AMySpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i=0; i<SpawnCount; i++)
	{
		SpawnActor();
	}
	
}

void AMySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMySpawner::SpawnActor()
{
	if (!ActorBpRef) return;

	int32 MaxSpawnAttempts = 100;
	for (int32 Attempt = 0; Attempt < MaxSpawnAttempts; Attempt++)
	{
		FBoxSphereBounds Bounds = SpawningVolume->CalcBounds(SpawningVolume->GetComponentTransform());
		FVector RandomLocation = FMath::RandPointInBox(Bounds.GetBox());

		bool bIsSafeLocation = true;
		for (const FVector& SpawnedLocation : SpawnedLocations)
		{
			if (MinSpawnDistance > FVector::Distance(RandomLocation, SpawnedLocation))
			{
				bIsSafeLocation = false;
				break;
			}
		}
		if (bIsSafeLocation)
		{
			GetWorld()->SpawnActor<ALevelGimmick>(ActorBpRef, RandomLocation, FRotator::ZeroRotator);
			SpawnedLocations.Add(RandomLocation);
			return;
		}
	}
}

