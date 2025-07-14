#include "Actors/LevelGimmick.h"

ALevelGimmick::ALevelGimmick()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(GetRootComponent());
	
}

void ALevelGimmick::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelGimmick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

