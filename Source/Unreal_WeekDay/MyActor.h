// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties (����Ƽ�� Awake)
	AMyActor();

protected:
	// Called when the game starts or when spawned (����Ƽ�� Start)
	virtual void BeginPlay() override;

public:	
	// Called every frame (����Ƽ�� Update)
	virtual void Tick(float DeltaTime) override;

};
