#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CEventTrigger.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACEventTrigger : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_EVENT_OneParam(ACEventTrigger, FEventTrigger, int32)

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	
public:	
	ACEventTrigger();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	
public:
	FEventTrigger	OnEventTrigger;
};
