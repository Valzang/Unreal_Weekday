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
	// Sets default values for this actor's properties (유니티의 Awake)
	AMyActor();

protected:
	// Called when the game starts or when spawned (유니티의 Start)
	virtual void BeginPlay() override;

public:	
	// Called every frame (유니티의 Update)
	virtual void Tick(float DeltaTime) override;

private:
	// 어디에서나 잘 보임
	UPROPERTY(EditAnywhere)
		int A = 10;
	// 인스턴스(=복사본)에서만 보임 ( 실제 씬에 배치된 게임 오브젝트 )
	UPROPERTY(EditInstanceOnly)
		int B = 20;

	// 디폴트 세팅(=원본)에서만 보임 ( 유니티로 따지면 프리팹 )
	UPROPERTY(EditDefaultsOnly)
		int C;

	// 보이기만 하고 수정 불가
	//UPROPERTY(VisibleAnywhere)
	//	int D = 40;


	// 블루프린트에서 가져오게끔 하려고 protected로 가져올 수 있게끔 해주기
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int D = 40;

};
