#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCube.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACCube : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;
public:	
	ACCube();

protected:
	virtual void BeginPlay() override;


};
