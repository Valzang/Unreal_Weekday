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
	// ���� ��� �ʹ� ���� Ŭ������ ������ ������, �Ʒ��� ������ �ؼ� ���.
		TSubclassOf<class ACSpawnActor> spawnClass[actorCount];

	class ACSpawnActor* spawnActors[actorCount];

	
public:	
	ACSpawner();

protected:
	virtual void BeginPlay() override;


};
