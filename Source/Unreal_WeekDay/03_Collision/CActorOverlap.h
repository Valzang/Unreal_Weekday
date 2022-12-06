#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CActorOverlap.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACActorOverlap : public AActor
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
	ACActorOverlap();

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
protected:
	virtual void BeginPlay() override;

};
