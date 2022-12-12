#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CParticles.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACParticles : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystem* Particles[5];
	
public:	
	ACParticles();

public:
	UFUNCTION()
		void PlayParticle(int32 index);

protected:
	virtual void BeginPlay() override;


};
