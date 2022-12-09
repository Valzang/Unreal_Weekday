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
	UPROPERTY(VisibleDefaultsOnly)
		class UPointLightComponent* Light2;
	
private:
	UFUNCTION()
		void OnLight();
	UFUNCTION()
		void OffLight();
	UFUNCTION()
		FString OnRandomLight(FLinearColor InColor);
public:	
	ACLight();

protected:
	virtual void BeginPlay() override;


};
