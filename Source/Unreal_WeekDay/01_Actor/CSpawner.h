#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpawner.generated.h"


#define actorCount 3

UCLASS()
class UNREAL_WEEKDAY_API ACSpawner : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	//UClass* spawnClass; 
	// 위의 경우 너무 많은 클래스가 나오기 때문에, 아래로 제한을 해서 사용.
		TSubclassOf<class ACSpawnActor> spawnClass[actorCount];

	class ACSpawnActor* spawnActors[actorCount];

	
public:	
	ACSpawner();

protected:
	virtual void BeginPlay() override;


};
