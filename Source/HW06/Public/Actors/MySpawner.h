#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpawner.generated.h"

class ALevelGimmick;
class UBoxComponent;

UCLASS()
class HW06_API AMySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AMySpawner();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, Category="Spawn")
	UBoxComponent* SpawningVolume;
	

private:
	UPROPERTY(EditAnywhere, Category="Spawn", meta=(AllowPrivateAcess = "true"))
	TSubclassOf<ALevelGimmick> ActorBpRef;
	
	UPROPERTY(EditAnywhere, Category="Spawn", meta=(AllowPrivateAcess = "true"))
	int32 SpawnCount;

	UPROPERTY(EditAnywhere, Category="Spawn", meta=(AllowPrivateAcess = "true"))
	float MinSpawnDistance;
	
	TArray<FVector> SpawnedLocations;

	void SpawnActor();
	
};
