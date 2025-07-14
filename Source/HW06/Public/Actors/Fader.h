#pragma once

#include "CoreMinimal.h"
#include "Actors/LevelGimmick.h"
#include "Fader.generated.h"

class UFadeComponent;
UCLASS()
class HW06_API AFader : public ALevelGimmick
{
	GENERATED_BODY()

public:
	AFader();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UFadeComponent* FadeComp;
};
