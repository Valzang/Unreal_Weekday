#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCylinder.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACCylinder : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	
public:	
	ACCylinder();

protected:
	virtual void BeginPlay() override;


};
