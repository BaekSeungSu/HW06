#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FadeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HW06_API UFadeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFadeComponent();

protected:
	virtual void BeginPlay() override;

private:
	float VisibleDuration;
	float HiddenDuration;

	bool bIsVisible;
	FTimerHandle FadeTimerHandle;
	
	UPROPERTY()
	AActor* Owner;

	void Fade();
	void ToggleVisibility(bool Visibility);
	void RandomizeProperties();
};
