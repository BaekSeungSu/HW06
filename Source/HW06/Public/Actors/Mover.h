// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/LevelGimmick.h"
#include "Mover.generated.h"

class UPathMoverComponent;
UCLASS()
class HW06_API AMover : public ALevelGimmick
{
	GENERATED_BODY()

public:
	AMover();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPathMoverComponent* PathMoverComp;
};
