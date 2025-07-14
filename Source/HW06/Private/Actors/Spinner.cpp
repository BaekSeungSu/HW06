#include "Actors/Spinner.h"
#include "Components/RotateComponent.h"

ASpinner::ASpinner()
{
	PrimaryActorTick.bCanEverTick = false;
	RotateComp = CreateDefaultSubobject<URotateComponent>(TEXT("RotateComponent"));
}

void ASpinner::BeginPlay()
{
	Super::BeginPlay();
}

void ASpinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}
