#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBox.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACBox : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh[3];
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

public:	
	ACBox();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnPhysics(int32 InIndex, FLinearColor InColor);


private:
	UMaterialInstanceDynamic* Materials[3];
	FVector		WorldLocation[3];
};
