// Fill out your copyright notice in the Description page of Project Settings.


#include "CSpawner.h"
#include "Global.h"
#include "CSpawnActor.h"

// Sets default values
ACSpawner::ACSpawner()
{

}

// Called when the game starts or when spawned
void ACSpawner::BeginPlay()
{
	Super::BeginPlay();

	FTransform transform;
	FVector location = GetActorLocation();

	for (int32 i = 0; i < actorCount; ++i)
	{
		// 예외처리
		if (!spawnClass[i])
			continue;
		
		//spawnActors[i] = GetWorld()->SpawnActor<ACSpawnActor>(spawnClass[i], transform);
		//spawnActors[i]->SetActorLocation(FVector(location.X, location.Y + i * 400, location.Z));
	 
		transform.SetLocation(FVector(location.X, location.Y + i * 400, location.Z));
		spawnActors[i] = GetWorld()->SpawnActor<ACSpawnActor>(spawnClass[i], transform);
	}	
}

