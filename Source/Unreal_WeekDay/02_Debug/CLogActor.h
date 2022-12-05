#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLogActor.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACLogActor : public AActor
{
	GENERATED_BODY()

	float Time = 0.0f;
public:	
	ACLogActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
