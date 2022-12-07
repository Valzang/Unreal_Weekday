#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLight.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACLight : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light;
	
private:
	UFUNCTION()
		void OnLight();
	UFUNCTION()
		void OffLight();
public:	
	ACLight();

protected:
	virtual void BeginPlay() override;


};
