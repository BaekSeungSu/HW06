#include "Actors/RotatingObject.h"

ARotatingObject::ARotatingObject()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(GetRootComponent());

	RotationSpeed = FRotator(0.0f, 0.0f, 0.0f);
}

void ARotatingObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate(DeltaTime);

}

void ARotatingObject::Rotate(float DeltaTime)
{
	AddActorLocalRotation(RotationSpeed * DeltaTime);
}

