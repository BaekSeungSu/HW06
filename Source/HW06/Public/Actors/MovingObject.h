// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class HW06_API AMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	FVector MoveOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	float MoveSpeed;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* StaticMeshComp;


private:
	void Move(float DeltaTime);

	FVector StartLocation;
	FVector EndLocation;
	FVector InitialDirection;
	FVector MoveDirection;
	
};
