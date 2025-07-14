#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGimmick.generated.h"

class UStaticMeshComponent;

UCLASS()
class HW06_API ALevelGimmick : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelGimmick();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneRoot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComp;
	


};
