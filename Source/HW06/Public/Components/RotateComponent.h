// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HW06_API URotateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	URotateComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float MaxSpeed = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float MinSpeed = 100.0f;


protected:
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
	
private:
	FRotator RotateSpeed;

	UPROPERTY()
	AActor* Owner;

	FTimerHandle RotationTimerHandle;
	float UpdateInterval;
	
	void UpdateRotation();
	void RandomizeProperties();
		
};
