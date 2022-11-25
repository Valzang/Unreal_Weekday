#pragma once
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class UNREAL_WEEKDAY_API CHelpers
{
public :
	template<typename T> static void GetAsset(T** outObject, FString inPath)
	{
		// inPath에서 에셋 가져오기
		ConstructorHelpers::FObjectFinder<T> asset(*inPath);
		// 성공시 성공했다고 디버그, 실패할 시 터짐
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outObject = asset.Object;
	}

	template<typename T> static void GetAssetDynamic(T** outObject, FString inPath)
	{
		T* obj = Cast<T>(StaticLoadObject(T::StaticClass(), NULL, *inPath));
		// !!obj  => obj != null
		verifyf(!!obj, L"!!asset");
		*outObject = obj;
	}

	template<typename T> static void CreateComponent(AActor* inActor, T** inComponent,
													 FName inName, USceneComponent* inParent = NULL)
	{
		*inComponent = inActor->CreateDefaultSubobject<T>(inName);
		if (!!inParent)
		{
			(*inComponent)->SetupAttachment(inParent);
			return;
		}

		inActor->SetRootComponent(*inComponent);
	}

	template<typename T> static void GetClass(TSubclassOf<T>* outClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outClass = asset.Class;
	}
};