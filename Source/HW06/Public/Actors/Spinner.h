#pragma once

#include "CoreMinimal.h"
#include "Actors/LevelGimmick.h"
#include "Spinner.generated.h"

class URotateComponent;
UCLASS()
class HW06_API ASpinner : public ALevelGimmick
{
	GENERATED_BODY()
public:
	ASpinner();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	URotateComponent* RotateComp;
};
