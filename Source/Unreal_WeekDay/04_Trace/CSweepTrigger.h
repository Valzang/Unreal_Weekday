#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSweepTrigger.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACSweepTrigger : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;


public:	
	ACSweepTrigger();

protected:
	virtual void BeginPlay() override;
};
