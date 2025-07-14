#include "Actors/Fader.h"
#include "Components/FadeComponent.h"

AFader::AFader()
{
	PrimaryActorTick.bCanEverTick = false;
	FadeComp = CreateDefaultSubobject<UFadeComponent>(TEXT("FadeComponent"));
}

void AFader::BeginPlay()
{
	Super::BeginPlay();
}

void AFader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
