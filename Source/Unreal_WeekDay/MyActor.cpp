// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Update와도 같은 Tick을 부를지 말지
	PrimaryActorTick.bCanEverTick = true;

	C = 30;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//String임
	FString str;
	str.Append("A : ");
	str.Append(FString::FromInt(A));

	str.Append(",B : ");
	str.Append(FString::FromInt(B));

	str.Append(",C : ");
	str.Append(FString::FromInt(C));

	str.Append(",D : ");
	str.Append(FString::FromInt(D));

	// 유니티의 Debug, 싱글톤임
	GLog->Log(str);
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

