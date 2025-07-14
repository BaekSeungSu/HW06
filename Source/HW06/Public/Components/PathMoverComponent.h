#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PathMoverComponent.generated.h"


class UTimelineComponent;
class UCurveFloat;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HW06_API UPathMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPathMoverComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float MaxSpeed = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float MinSpeed = 100.0f;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float MaxDistance = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float MinDistance = 200.0f;

protected:
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
	
private:
	FVector StartLocation;
	FVector MoveDirection;
	float MoveSpeed;
	float MoveDistance;
	float TotalDistance;

	UPROPERTY()
	AActor* Owner;
	
	FTimerHandle MovementTimerHandle;
	float UpdateInterval;
	
	void UpdateMovement();
	void RandomizeProperties();
};


