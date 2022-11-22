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
};