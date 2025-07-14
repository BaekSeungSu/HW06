#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingObject.generated.h"

UCLASS()
class HW06_API ARotatingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	FRotator RotationSpeed;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* StaticMeshComp;
	
private:
	void Rotate(float DeltaTime);

};
